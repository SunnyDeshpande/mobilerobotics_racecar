/* Reads velocity (linear and angular) commands from move_base node and then publishes it to topic,
 * that the Arduino servo controller will subscribe to. 
 * 
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the 
 *     names of its contributors may be used to endorse or promote products 
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <math.h>
#include "ros/ros.h"
#include "std_msgs/UInt32.h"
#include "car_control/joystick.h"
#include "geometry_msgs/Twist.h"
#include <sensor_msgs/Joy.h>
#include <sstream>

#include "nav_msgs/Odometry.h"

// For debugging purposes //
int throttleLeverPositionGlobal = 0;
int steeringJoystickPositionGlobal = 0;
uint32_t joynavigationGlobal = 0;
/////////////////////////////

uint32_t joynavigation = 90100;
uint32_t autonavigation = 90100;
double steering_angle;
double radius;
std_msgs::UInt32 navigation;

// make sure this is the same as in the Arduino
const double runFrequency = 60;
int steeringPosition = 90;
int ThrottlePosition = 100;

double maxVelocity = 0.5;
double maxSteering = 0.005;
bool flag = false;
int throttle = 100;
int steering = 90;
double wheelbase = 0.5;

// to put into main() for debug
double angularZprintout = 0;
double linearXprintout = 0;

// stores x, y, z, and total position values over the past 0.1 seconds to calculate linear displacement
double positionArray[4][6];
double xPosition, yPosition, zPosition, pythagoreanDistance, deltaDistance;

// concurrently stores timestamps
uint32_t timeArray[2][6];
uint32_t seconds, nanoseconds, deltaSeconds, deltaNanoseconds;
double deltaTime; 

// input as in PID input, setpoint, output
double linearVelocity = 0;

int debugIterations = 1;

double degreesToRadians(double angle_in_degrees)
{
	return angle_in_degrees * (M_PI / 180.0);
}

/**********************************************************************************
 If no signal is received from the XBox controller after a while due to a disconnect 
 or error, "steering 90 throttle 110" is sent to the Arduino to instruct it to turn
 the car straight and brake. 
 **********************************************************************************/
void stopCallback()
{
	navigation.data = 97100;
}

/**********************************************************************************
 Calculates linear speed based on visual odometry. 
 
 Note to self: DO NOT use odometry for reverse, stick with proprietary Cinnabar. 
 The reverse function on this particular car is very weird and only used in short
 bursts, as recovery manouevres, by the local planner. 
 **********************************************************************************/
void calcSpeedCallback(const nav_msgs::Odometry::ConstPtr& odom)
{
	// updates the position array by shifting every value one position left
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 5; ++col)
		{
			positionArray[row][col] = positionArray[row][col + 1];
		}
	}
	
	positionArray[0][5] = odom->pose.pose.position.x;
	positionArray[1][5] = odom->pose.pose.position.y;
	positionArray[2][5] = odom->pose.pose.position.z;
	
	// makes life easier 
	xPosition = positionArray[0][5];
	yPosition = positionArray[1][5];
	zPosition = positionArray[2][5];
	
	// calculates linear displacement
	pythagoreanDistance = sqrt( pow(xPosition, 2) + pow(yPosition, 2) + pow(zPosition, 2) );
	
	positionArray[3][5] = pythagoreanDistance;
	
	if (pythagoreanDistance > positionArray[3][0])
	{
		deltaDistance = pythagoreanDistance - positionArray[3][0];
	}
	else
	{
		deltaDistance = positionArray[3][0] - pythagoreanDistance;
	}
	
	// updates the time array by shifting every value one position left
	for (int row = 0; row < 2; ++row)
	{
		for (int col = 0; col < 5; ++col)
		{
			timeArray[row][col] = timeArray[row][col + 1];
		}
	}
	
	timeArray[0][5] = odom->header.stamp.sec;
	timeArray[1][5] = odom->header.stamp.nsec;
	
	// makes life easier
	seconds = timeArray[0][5];
	nanoseconds = timeArray[1][5];
	
	// calculates time elapsed
	if (seconds == timeArray[0][0])
	{
		deltaNanoseconds = nanoseconds - timeArray[1][0];
	}
	else
	{
		deltaNanoseconds = nanoseconds + 1000000000 - timeArray[1][0];
	}
	
	deltaTime = deltaNanoseconds / pow(10, 9);
	
	// now we calculate the linear velocity
	linearVelocity = deltaDistance / deltaTime;
}

void joystickCallback(const sensor_msgs::Joy::ConstPtr& msg) 
{
	int button = msg->buttons[1];
	if (button == 1)
	{
		flag = !flag;
	}
	
	// Store value here for manipulation (-1 for flipping between forward)
	double frontBackAx = msg->axes[1] * -1;  	

	// for normal forward operation. the two integers must be declared in this scope. 
	int steeringJoystickPosition = 97 + (msg->axes[3] * 30); //modified to axis 2->3

	//int throttleLeverPosition = 100 - (msg->axes[1] * 15);
	int throttleLeverPosition = 100 - (frontBackAx * 15);

	// extreme low speed on Y button hold for mapping purposes
	//if (msg->axes[3] == 1)
	//{
//		throttleLeverPosition = 93;
//	}

	// this makes the brakes more responsive and enables a reverse function
	// if (msg->axes[1] < -0.03)
	if (frontBackAx < -0.03)
	{

		// throttleLeverPosition = 100 - (msg->axes[1] * 25);
		throttleLeverPosition = 100 - (frontBackAx * 25);
	}

	// emergency brake
	if (msg->axes[5] == -1)
	{
		throttleLeverPosition = 150;
	}
	
	// For debugging purposes
	throttleLeverPositionGlobal = throttleLeverPosition;
	steeringJoystickPositionGlobal = steeringJoystickPosition;

	// first three digits steering, last three digits throttle
	joynavigation = (steeringJoystickPosition * 1000) + throttleLeverPosition;
	
	// For debugging purposes	
	joynavigationGlobal = joynavigation;

	timeSinceLastMessage = 0;
}

/**********************************************************************************
 The XBox controller outputs a (class?) of button, joystick, and lever position data.
 In here, we call it msg, and extract the data corresponding to the positions of the 
 steering joystick and acceleration lever. 
 This callback only executes upon receipt of message from joystick, and does not 
 directly send a message to the Arduino. It only modifies the message sent. 
 **********************************************************************************/
void realnavigationCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
        
	if (!flag)
	{
		double angular_z = msg->angular.z;	
		
		angularZprintout = msg->angular.z;
		linearXprintout = msg->linear.x;
		//-ROS_INFO("Veer_DEBUG");
		 
	
		double steering_ratio = 0;
		
		if (angular_z == 0)
		{
			steering_ratio = 0;
		} 
		//-else if 
		//- {
			if (linearVelocity > 0.1)
			{
				radius = (linearVelocity / msg->angular.z);
			}
			else
			{
				radius = (0.1 / msg->angular.z);
			}
			// radius = (msg->linear.x / msg->angular.z);
		
			steering_angle = atan(wheelbase / radius); 
			
			
			throttle = 100 + ((msg->linear.x)/0.10)*6;
			ROS_INFO("My Throttle Val %i", throttle);
			steering_ratio = steering_angle/degreesToRadians(30);
			
			if (steering_ratio > 3.0)
			{
				steering_ratio = 3.0;
			}
			
			if (steering_ratio < -3.0)
			{
				steering_ratio = -3.0;
			}
		//-}
		
		steering = 97 + steering_ratio * 20;
 
		autonavigation = (steering * 1000) + throttle;  
		//- ROS_INFO("Auto =  %d", autonavigation);
		timeSinceLastMessage = 0;
	}
}

int main(int argc, char **argv)
{
   /**********************************************************************************
    The ros::init() function needs to see argc and argv so that it can perform
    any ROS arguments and name remapping that were provided at the command line.
    For programmatic remappings you can use a different version of init() which takes
    remappings directly, but for most command-line programs, passing argc and argv is
    the easiest way to do it.  The third argument to init() is the name of the node.
  
    You must call one of the versions of ros::init() before using any other
    part of the ROS system.
    **********************************************************************************/
	ros::init(argc, argv, "car_control");

   /**********************************************************************************
    NodeHandle is the main access point to communications with the ROS system.
    The first NodeHandle constructed will fully initialize this node, and the last
    NodeHandle destructed will close down the node.
    **********************************************************************************/
	ros::NodeHandle n;

   /**********************************************************************************
    Subscribes to topic joy, which the joystick publishes button and lever data to. 
    On receipt of data, executes function joystickCallback, which converts joystick
    data to a UInt8 which will be sent to the Arduino. 
    **********************************************************************************/
	ros::Subscriber sub = n.subscribe("cmd_vel", 1, realnavigationCallback);
	ros::Subscriber suby = n.subscribe("joy", 1, joystickCallback);
	ros::Subscriber subz = n.subscribe("camera/odom", 1, calcSpeedCallback);

   /**********************************************************************************
    The advertise() function is how you tell ROS that you want to publish on a given 
    topic name. This invokes a call to the ROS master node, which keeps a registry of 
    who is publishing and who is subscribing. After this advertise() call is made, 
    the master node will notify anyone who is trying to subscribe to this topic name,
    and they will in turn negotiate a peer-to-peer connection with this node.  
    advertise() returns a Publisher object which allows you to publish messages on 
    that topic through a call to publish(). Once all copies of the returned Publisher
    object are destroyed, the topic will be automatically unadvertised.
   
    The second parameter to advertise() is the size of the message queue used for
    publishing messages.  If messages are published more quickly than we can send them,
    the number here specifies how many messages to buffer up before throwing some away.
    **********************************************************************************/
	ros::Publisher pub = n.advertise<std_msgs::UInt32>("cinnabar", 1000);

	ros::Rate loop_rate(runFrequency);

	while (ros::ok())
	{
		// DEBUG
		// ROS_INFO("%u \t %f \t %f \t", navigation.data, radius, steering_angle);
		// ROS_INFO("%u \t %f \t %f \t", navigation.data, linearXprintout, angularZprintout);
	
       	ROS_INFO("Iteration %i", debugIterations);
		debugIterations++;

		// For debugging purposes	
		//ROS_INFO("Throttle lever position: %i", throttleLeverPositionGlobal);
		//ROS_INFO("Steering joystick position: %i", steeringJoystickPositionGlobal);		
		//ROS_INFO("Joynavigation: %u", joynavigationGlobal);	

		// couts the ENTIRE DISTANCE ARRAY
		/*
		for (int row = 0; row < 4; ++row)
		{
			ROS_INFO("D%i \t %f \t %f \t %f \t %f \t %f \t %f \t %f", 
					row + 1,
					positionArray[row][0], 
					positionArray[row][1], 
					positionArray[row][2], 
					positionArray[row][3], 
					positionArray[row][4],
					positionArray[row][5],
					deltaDistance						);
		}
		
		
		// couts the ENTIRE TIME ARRARY
		
		for (int row = 0; row < 2; ++row)
		{
			ROS_INFO("T%i \t %u \t %u \t %u \t %u \t %u \t %u \t %f", 
					row + 1,
					timeArray[row][0], 
					timeArray[row][1], 
					timeArray[row][2], 
					timeArray[row][3], 
					timeArray[row][4],
					timeArray[row][5],
					deltaTime						);
		}
		*/
		
		 ROS_INFO("dS: %f \tdT: %f \tV: %f", deltaDistance, deltaTime, linearVelocity);
	
		// ROS_INFO("x %f \t y %f \t z %f \t E %f \t", xPosition, yPosition, zPosition, pythagoreanDistance);

		timeSinceLastMessage = timeSinceLastMessage + (1 / runFrequency);
    
		
	   /*******************************************************************************
		The publish() function is how you send messages. The parameter is the message
		object. The type of this object must agree with the type given as a template
		parameter to the advertise<>() call, as was done in the constructor above.
		*******************************************************************************/
				
		if (flag)
			{
			navigation.data = joynavigation;
			pub.publish(navigation);
			}
		else
			{            
			ROS_INFO("writing for auto navi");
			navigation.data = autonavigation;
			if (timeSinceLastMessage > noMessageThreshold)
			{	 
				ROS_INFO("Stop_CallBack JoyNav\n");
				stopCallback();
			}	
			pub.publish(navigation);
		}
		

		
		ROS_INFO("%u \t %f \t %f \t", navigation.data, radius, steering_angle);
          	ROS_INFO("%u \t %f \t %f \t", navigation.data, linearXprintout, angularZprintout);
	
	        

		ros::spinOnce();

		loop_rate.sleep();
	}

	return 0;
}
