#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile,ReliabilityPolicy
import tf_transformations as tr
from std_msgs.msg import String, Header, ColorRGBA
from nav_msgs.msg import OccupancyGrid, MapMetaData, Odometry
from geometry_msgs.msg import Twist, PoseStamped, Point
from sensor_msgs.msg import LaserScan
from visualization_msgs.msg import Marker, MarkerArray
from math import sqrt, cos, sin, pi, atan2
from threading import Thread, Lock
from math import pi, log, exp
from builtin_interfaces.msg import Time, Duration
import random
import numpy as np
import sys
import pickle


class Particle(object):
    def __init__(self, id, x,y, theta):
        self.x = x
        self.y = y
        self.id = id
        self.theta = theta

    def copy(self):
        return Particle(self.id, self.x, self.y, self.theta)
    
class ParticleFilter(object):
    def __init__(self, num_particles, occ_grid_map, xmin, xmax, ymin, ymax,
                 laser_min_range, laser_max_range, laser_min_angle, laser_max_angle,
                 dynamics_translation_noise_std_dev,
                 dynamics_orientation_noise_std_dev,
                 beam_range_measurement_noise_std_dev, node, n_thresh=0):
        
        self.num_particles = num_particles
        self.n_thresh = n_thresh
        self.ogm = occ_grid_map
        self.grid_map = np.array(self.ogm['data'], dtype='int8')
       

        height = self.ogm['info'].get('height', 0)
        width = self.ogm['info'].get('width', 0)
        self.grid_map = self.grid_map.reshape((height, width)) 
        self.height = height
        self.width = width
        
        self.grid_bin = (self.grid_map == 0).astype('uint8')  # Cell is True iff probability of being occupied is zero

        # Workspace boundaries 
        self.xmax = xmax
        self.xmin = xmin
        self.ymin = ymin
        self.ymax = ymax
        
        self.laser_max_angle = laser_max_angle
        self.laser_min_angle = laser_min_angle
        self.laser_max_range = laser_max_range
        self.laser_min_range = laser_min_range

        # Std deviation of noise affecting translation in the dynamics model for particles 
        self.dynamics_translation_noise_std_dev = dynamics_translation_noise_std_dev

        # Std deviation of noise affecting orientation in the dynamics model for particles 
        self.dynamics_orientation_noise_std_dev = dynamics_orientation_noise_std_dev

        # Std deviation of noise affecting measured range from the laser measurement model  
        self.beam_range_measurement_noise_std_dev = beam_range_measurement_noise_std_dev

        # Number of laser beams to simulate when predicting what a
        # particle's measurement is going to be
        self.eval_beams = 9

        # Previous odometry measurement of the robot
        self.last_robot_odom = None

        # Current odometry measurement of the robot 
        self.robot_odom = None

        # Relative motion since the last time particles were updated
        self.dx = 0
        self.dy = 0
        self.dyaw = 0

        self.particles = []
        self.weights = []

        # ROS Node
        self.node = node

    def get_random_free_state(self):
        while True:
            
            # Note: we initialize particles closer to the robot's initial
            # position in order to make the initialization easier
            xrand = np.random.uniform(self.xmin, self.xmax)
            yrand = np.random.uniform(self.ymin, self.ymax)
            row, col = self.metric_to_grid_coords(xrand, yrand)
            if self.grid_bin[row, col]:
                theta = np.random.uniform(0, 0.01)
                # theta = np.random.uniform(0, 2*pi)
                return xrand, yrand, theta
        
    def init_particles(self):
        """Initializes particles uniformly randomly with map frame coordinates, 
        within the boundaries set by xmin,xmax, ymin,ymax"""
        for i in range(self.num_particles):
            xrand, yrand, theta = self.get_random_free_state()
            # Note: same orientation as the initial orientation of the robot
            # to make initialization easier
            self.particles.append(Particle(i, xrand, yrand, theta))

    @staticmethod
    def exponentiate_and_normalize(x):
        b = x.max()
        x = np.exp(x - b)
        return x / x.sum()

    def handle_observation(self, laser_scan, dt):
        """Does prediction, weight update, and resampling."""
        # TODO: for every particle
        # 1) Predict its relative motion since the last time an observation was received using
        # predict_particle_odometry().
        # 2) Compute the squared norm of the difference between the particle's predicted laser scan
        # and the actual laser scan 
        errors = []
        
        # TODO: exponentiate the prediction errors you computed above
        # using numerical stability tricks such as
        # http://timvieira.github.io/blog/post/2014/02/11/exp-normalize-trick/
        # if you think it is necessary
        

        N_eff = 0
        print ("effective sample size", N_eff)
       

        # Do resampling. Depending on how you implement it you might
        # or might not need to normalize your weights by their sum, so
        # they are treated as probabilities
        
        self.resample()
            
    def resample(self):
        """Implements resampling in particle filters"""

        # TODO: sample particle i with probability that  
        # is proportional to its weight w_i. Sampling
        # can be done with repetition/replacement, so
        # you can sample the same particle more than once.
        
        pass

    def simulate_laser_scan_for_particle(self, x, y, yaw_in_map, angles, min_range, max_range):
        """If the robot was at the given particle, what would its laser scan
        be (in the known map)? Returns the predicted laser ranges if a particle with state (x,y,yaw_in_map)
        is to scan along relative angles in angles."""
        
        ranges = []
        range_step = self.ogm['info']['resolution']  # meters per cell

        # TODO: for every relative angle in angles
        # 1. Compute the absolute angle based on the robot's orientation
        # 2. Do ray tracing from (x,y) along the abosulte angle using step size range_step 
        #    (a) If the currently examined point is within the bounds of the workspace
        #        stop if it meets an obstacle or if it reaches max_range
        #    (b) If the currently examined point is outside the bounds of the workspace
        #        stop if it reaches max_range
        # 3. Return the computed collection of ranges corresponding to the given angles

        return ranges

    def subsample_laser_scan(self, laser_scan_msg):
        """Subsamples a set number of beams (self.eval_beams) from the incoming actual laser scan. It also
        converts the Inf range measurements into max_range range measurements, in order to be able to 
        compute a difference."""
    
        # Just like in the occupancy grid mapping assignment you might need this snippet
        # to convert the laser points from the husky_1/base_laser frame, whose z-axis points downwards
        # to the same frame pointing upwards

        N = len(laser_scan_msg.ranges)
        ranges_in_upwards_baselaser_frame = laser_scan_msg.ranges
        angles_in_baselaser_frame = [(laser_scan_msg.angle_max - laser_scan_msg.angle_min)*float(i)/N + laser_scan_msg.angle_min for i in range(N)]

        step = N/self.eval_beams
        angles_in_upwards_baselaser_frame = angles_in_baselaser_frame[::int(step)]
        ranges_in_upwards_baselaser_frame = ranges_in_upwards_baselaser_frame[::int(step)]

        assert (len(ranges_in_upwards_baselaser_frame) == len(angles_in_upwards_baselaser_frame))
        
        actual_ranges = []
        for r in ranges_in_upwards_baselaser_frame:
            
            if r >= self.laser_min_range and r <= self.laser_max_range:
                actual_ranges.append(r)
            
            if r < self.laser_min_range:
                actual_ranges.append(self.laser_min_range)
            
            if r > self.laser_max_range:
                actual_ranges.append(self.laser_max_range)
        

        return actual_ranges, angles_in_upwards_baselaser_frame
    
    def get_prediction_error_squared(self, laser_scan_msg, particle):
        """
        This function evaluates the squared norm of the difference/error between the  
        scan in laser_scan_msg and the one that was predicted by the given particle. 
        
        Assume that the bearing of each beam relative to the robot's orientation has zero noise, 
        so the only noise in the measurement comes from the range of each beam and is 
        distributed as N(0, beam_range_measurement_std_dev^2)
        """

        # If the particle is out of the bounds of the workspace
        # give it a large error
        if particle.x < self.xmin or particle.x > self.xmax:
            return 300

        if particle.y < self.ymin or particle.y > self.ymax:
            return 300


        # If the particle falls inside an obstacle
        # give it a large error
        row, col = self.metric_to_grid_coords(particle.x, particle.y)
        if row < self.height and col < self.width: 
            if self.grid_map[row, col] == 100:
                return 300
        else:
            return 300
        
        
        assert (self.laser_min_range >= 0)
        assert (self.laser_max_range > 0)

        # TODO: subsample the recived actual laser scan using the
        # subsample_laser_scan method above
        
        # TODO: simulate a laser scan using one of the methods of this class
        
        # TODO: compute the difference bwteen predicted ranges and actual ranges
        # Take the squared norm of that difference
        error = 0
        return error

    def handle_odometry(self, robot_odom):
        """Compute the relative motion of the robot from the previous odometry measurement
        to the current odometry measurement."""
        self.last_robot_odom = self.robot_odom
        self.robot_odom = robot_odom

        if self.last_robot_odom:
            
            p_map_currbaselink = np.array([self.robot_odom.pose.pose.position.x,
                                           self.robot_odom.pose.pose.position.y,
                                           self.robot_odom.pose.pose.position.z])

            p_map_lastbaselink = np.array([self.last_robot_odom.pose.pose.position.x,
                                           self.last_robot_odom.pose.pose.position.y,
                                           self.last_robot_odom.pose.pose.position.z])

            q_map_lastbaselink = np.array([self.last_robot_odom.pose.pose.orientation.x,
                                           self.last_robot_odom.pose.pose.orientation.y,
                                           self.last_robot_odom.pose.pose.orientation.z,
                                           self.last_robot_odom.pose.pose.orientation.w])

            q_map_currbaselink = np.array([self.robot_odom.pose.pose.orientation.x,
                                           self.robot_odom.pose.pose.orientation.y,
                                           self.robot_odom.pose.pose.orientation.z,
                                           self.robot_odom.pose.pose.orientation.w])
            
            R_map_lastbaselink = tr.quaternion_matrix(q_map_lastbaselink)[0:3,0:3]
            
            p_lastbaselink_currbaselink = R_map_lastbaselink.transpose().dot(p_map_currbaselink - p_map_lastbaselink)
            q_lastbaselink_currbaselink = tr.quaternion_multiply(tr.quaternion_inverse(q_map_lastbaselink), q_map_currbaselink)
            
            _, _, yaw_diff = tr.euler_from_quaternion(q_lastbaselink_currbaselink) 

            dt_since_last_odom = (self.robot_odom.header.stamp.sec - self.last_robot_odom.header.stamp.sec)
            # Calculate time difference in nanoseconds
            dt_since_last_scan_nsec = (self.robot_odom.header.stamp.nanosec - self.last_robot_odom.header.stamp.nanosec)
            # Convert nanoseconds to seconds and add to the time difference in seconds
            dt_since_last_odom += dt_since_last_scan_nsec / 1e9

            self.dyaw = yaw_diff/dt_since_last_odom
            self.dx = p_lastbaselink_currbaselink[0]/dt_since_last_odom
            self.dy = p_lastbaselink_currbaselink[1]/dt_since_last_odom

            
    def predict_particle_odometry(self, particle,dt):
        """
        Where will the particle go after time dt passes?
        This function modifies the particle's state by simulating the effects
        of the given control forward in time. 

        Assume Dubins dynamics with variable forward velocity for the Husky.
        """
 
        nx = random.gauss(0, self.dynamics_translation_noise_std_dev)
        ny = random.gauss(0, self.dynamics_translation_noise_std_dev)
        ntheta = random.gauss(0, self.dynamics_orientation_noise_std_dev)

        v = sqrt(self.dx**2 + self.dy**2)

        # Don't let the particle propagation be dominated by noise
        if abs(v) < 1e-10 and abs(self.dyaw) < 1e-5:
            return
       
        particle.x += v * cos(particle.theta) * dt + nx
        particle.y += v * sin(particle.theta) * dt + ny
        particle.theta += self.dyaw * dt + ntheta

        
    def metric_to_grid_coords(self, x, y): 
        """Converts metric coordinates to occupancy grid coordinates"""
        
        origin_x = self.ogm['info']['origin']['position']['x']
        origin_y = self.ogm['info']['origin']['position']['y']
        resolution = self.ogm['info']['resolution']
        height = self.ogm['info']['height']
        width = self.ogm['info']['width']

        gx = (x - origin_x) / resolution
        gy = (y - origin_y) / resolution
        row = min(max(int(gy), 0), height-1)
        col = min(max(int(gx), 0), width-1)
        return (row, col)
        

class MonteCarloLocalization(Node):
    
    def __init__(self, num_particles, xmin, xmax, ymin, ymax):
      
        super().__init__('monte_carlo_localization')
        #############param decleartion##########################################################
        self.declare_parameter('map_file')
        self.declare_parameter('dynamics_translation_noise_std_dev')
        self.declare_parameter('dynamics_orientation_noise_std_dev')
        self.declare_parameter('beam_range_measurement_noise_std_dev')
        ###########################################################################################
        
        self.map_file = self.get_parameter('map_file').value
        self.dynamics_translation_noise_std_dev = self.get_parameter('dynamics_translation_noise_std_dev').value
        self.dynamics_orientation_noise_std_dev = self.get_parameter('dynamics_orientation_noise_std_dev').value
        self.beam_range_measurement_noise_std_dev = self.get_parameter('beam_range_measurement_noise_std_dev').value
        
        ###################################################################################
        pkl_file = open(self.map_file, 'rb')
        self.ogm = pickle.load(pkl_file)
        pkl_file.close()
        ########################################################################################


        self.q_baselink_baselaser = np.array([1.0, 0, 0, 0])
        self.R_baselink_baselaser = tr.quaternion_matrix(self.q_baselink_baselaser)[0:3,0:3]
        self.p_baselink_baselaser = np.array([0.337, 0.0, 0.308])

        self.pf = ParticleFilter(num_particles, self.ogm, xmin, xmax, ymin, ymax, 0, 0, 0, 0,
                                 self.dynamics_translation_noise_std_dev,
                                 self.dynamics_orientation_noise_std_dev,
                                 self.beam_range_measurement_noise_std_dev, self)
        
        self.pf.init_particles()
        self.last_scan = None
        self.mutex = Lock()
        ################################Publisher##################################################
        self.laser_points_marker_pub = self.create_publisher(Marker,'debug/laser_points',1) 
        self.particles_pub = self.create_publisher(MarkerArray,'particle_filter/particles', 1)

        ########################Subcriber#####################################################
        self.odom_sub = self.create_subscription(Odometry,'odom', self.odometry_callback, QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE)) #need to change according yor odometey topic
        self.laser_sub = self.create_subscription(LaserScan,'scan', self.laser_scan_callback,QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE))  #need to chage according your scan topic
        ######################################newly_added########################################################
       
        self.timer = self.create_timer(1.0, self.publish_particle_markers)

   
     ######################################################################################################################
    def odometry_callback(self, msg):
        self.mutex.acquire()
        self.pf.handle_odometry(msg)
        self.mutex.release()
    
    def get_2d_laser_points_marker(self, timestamp, frame_id, pts_in_map, marker_id, rgba):
        msg = Marker()
        msg.header.stamp = timestamp
        msg.header.frame_id = frame_id
        msg.ns = 'laser_points'
        msg.id = marker_id
        msg.type = 6
        msg.action = 0
        msg.points = [Point(x=pt[0],y=pt[1],z=pt[2]) for pt in pts_in_map]
        msg.colors = [rgba for _ in pts_in_map]
        
        for pt in pts_in_map:
            assert((not np.isnan(pt).any()) and np.isfinite(pt).all())
           
        msg.scale.x = 0.1 
        msg.scale.y = 0.1
        msg.scale.z = 0.1

        
        return msg
        
        
    def laser_scan_callback(self, msg):
        self.pf.laser_min_angle = msg.angle_min
        self.pf.laser_max_angle = msg.angle_max
        self.pf.laser_min_range = msg.range_min
        self.pf.laser_max_range = msg.range_max
        #check with ranges
        dt_since_last_scan = 0
        
        if self.last_scan:
            dt_since_last_scan_sec = (msg.header.stamp.sec - self.last_scan.header.stamp.sec)
            # Calculate time difference in nanoseconds
            dt_since_last_scan_nsec = (msg.header.stamp.nanosec - self.last_scan.header.stamp.nanosec)
            # Convert nanoseconds to seconds and add to the time difference in seconds
            dt_since_last_scan_sec += dt_since_last_scan_nsec / 1e9
            dt_since_last_scan = dt_since_last_scan_sec

        self.mutex.acquire()
        self.publish_laser_pts(msg)
        self.pf.handle_observation(msg, dt_since_last_scan)

        self.pf.dx = 0
        self.pf.dy = 0
        self.pf.dyaw = 0
                
        self.mutex.release()
        self.last_scan = msg
      

    def publish_laser_pts(self, msg):
        """Publishes the currently received laser scan points from the robot, after we subsampled
        them in order to comparse them with the expected laser scan from each particle."""
        if self.pf.robot_odom is None:
            return

        subsampled_ranges, subsampled_angles = self.pf.subsample_laser_scan(msg)
        
        N = len(subsampled_ranges)
        x = self.pf.robot_odom.pose.pose.position.x
        y = self.pf.robot_odom.pose.pose.position.y
        _, _ , yaw_in_map = tr.euler_from_quaternion(np.array([self.pf.robot_odom.pose.pose.orientation.x,
                                                               self.pf.robot_odom.pose.pose.orientation.y,
                                                               self.pf.robot_odom.pose.pose.orientation.z,
                                                               self.pf.robot_odom.pose.pose.orientation.w]))
        
        pts_in_map = [ (x + r*cos(theta + yaw_in_map),
                        y + r*sin(theta + yaw_in_map),
                        0.3) for r,theta in zip(subsampled_ranges, subsampled_angles)]

        lpmarker = self.get_2d_laser_points_marker(msg.header.stamp, 'odom', pts_in_map, 30000, ColorRGBA(r=0.0,g=0.0,b=1.0,a=1.0))
      
        self.laser_points_marker_pub.publish(lpmarker)
        
        
    def get_particle_marker(self, particle, marker_id, avg=False):
        """Returns an rviz marker that visualizes a single particle"""
        particle_marker = Marker()
        particle_marker.header.stamp = self.get_clock().now().to_msg() #timestamp
        particle_marker.header.frame_id = 'odom'
        particle_marker.ns = 'particles'
        particle_marker.id = marker_id
        particle_marker.type = Marker.ARROW 
        particle_marker.action = Marker.ADD 
        lifetime_duration = Duration()
        lifetime_duration.sec = 1 
        particle_marker.lifetime = lifetime_duration
        
        yaw_in_map = particle.theta
        vx = cos(yaw_in_map)
        vy = sin(yaw_in_map)

        if avg:
            particle_marker.color = ColorRGBA(r=0.0,g=0.0,b=1.0,a=1.0)
            particle_marker.points.append(Point(x=particle.x, y=particle.y, z=0.3))
            particle_marker.points.append(Point(x=particle.x + 0.3*vx, y=particle.y + 0.3*vy, z=0.3))
        else:
            particle_marker.color = ColorRGBA(r=0.0,g=1.0,b=0.0,a=0.1)
            particle_marker.points.append(Point(x=particle.x, y=particle.y, z=0.2))
            particle_marker.points.append(Point(x=particle.x + 0.3*vx, y=particle.y + 0.3*vy, z=0.2))
        
        particle_marker.scale.x = 0.05
        particle_marker.scale.y = 0.15
        particle_marker.scale.z = 0.1
        return particle_marker

    def publish_particle_markers(self):
        """ Publishes the particles of the particle filter in rviz"""
        
        marker_array = MarkerArray()
        

        
        for i, particle in enumerate(self.pf.particles):
            particle_marker = self.get_particle_marker(particle, i)
            
            marker_array.markers.append(particle_marker)

        pos = np.array([[p.x, p.y, p.theta] for p in self.pf.particles])
        avg_pos = np.mean(pos, axis=0)
        avg_particle = Particle(-1, avg_pos[0], avg_pos[1], avg_pos[2])
        avg_particle_marker = self.get_particle_marker(avg_particle, i+1, avg=True)
        marker_array.markers.append(avg_particle_marker)
           
        self.particles_pub.publish(marker_array)
        
   


def main(args=None):
    
    xmin = -3
    xmax = 3
    ymin = -3
    ymax = 3
    num_particles = 300

    rclpy.init(args=args)
    node = MonteCarloLocalization(num_particles, xmin, xmax, ymin, ymax)    
   
    rclpy.spin(node)
    node.node.destroy_node()
    rclpy.shutdown()
            
if __name__ == '__main__':
    main()


