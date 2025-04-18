// #include <math.h>
// #include "ros/ros.h"
// #include "std_msgs/UInt32.h"
// #include "car_control/joystick.h"
// #include "geometry_msgs/Twist.h"
// #include <sensor_msgs/Joy.h>
// #include <sstream>

// #include "nav_msgs/Odometry.h"

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "sensor_msgs/msg/joy.hpp"
using std::placeholders::_1;

bool flag = false;

int throttleLeverPositionGlobal = 0;
int steeringJoystickPositionGlobal = 0;
int32_t joynavigationGlobal = 0;

int32_t joynavigation = 97100;

// time in seconds since last joy message received before automatic stop
const double noMessageThreshold = 0.15;
double timeSinceLastMessage = noMessageThreshold;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("echo")
    {
      subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
      "joy", 10, std::bind(&MinimalSubscriber::joystickCallback, this, _1));
      publisher_ = this->create_publisher<std_msgs::msg::Int32>("micro_ros_arduino_subscriber", 10);
    // 	subscription_ = this->create_subscription<std_msgs::msg::String>(
      // "joy", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

  private:
  	void joystickCallback(const sensor_msgs::msg::Joy::SharedPtr msg) 
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

		RCLCPP_INFO(this->get_logger(), "throttleLeverPositionGlobal: '%i'", throttleLeverPositionGlobal);
		RCLCPP_INFO(this->get_logger(), "steeringJoystickPositionGlobal: '%i'", steeringJoystickPositionGlobal);

		// first three digits steering, last three digits throttle
		joynavigation = (steeringJoystickPosition * 1000) + throttleLeverPosition;
		
		// For debugging purposes	
		joynavigationGlobal = joynavigation;

		auto message = std_msgs::msg::Int32();
		message.data = joynavigation;

		publisher_->publish(message);

		timeSinceLastMessage = 0;
	}
    // void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    // {
    //   RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    // }
    // rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;


    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}

// int main(int argc, char **argv)
// {
//    /**********************************************************************************
//     The ros::init() function needs to see argc and argv so that it can perform
//     any ROS arguments and name remapping that were provided at the command line.
//     For programmatic remappings you can use a different version of init() which takes
//     remappings directly, but for most command-line programs, passing argc and argv is
//     the easiest way to do it.  The third argument to init() is the name of the node.
  
//     You must call one of the versions of ros::init() before using any other
//     part of the ROS system.
//     **********************************************************************************/
// 	ros::init(argc, argv, "car_control");

//    /**********************************************************************************
//     NodeHandle is the main access point to communications with the ROS system.
//     The first NodeHandle constructed will fully initialize this node, and the last
//     NodeHandle destructed will close down the node.
//     **********************************************************************************/
// 	ros::NodeHandle n;

//    /**********************************************************************************
//     Subscribes to topic joy, which the joystick publishes button and lever data to. 
//     On receipt of data, executes function joystickCallback, which converts joystick
//     data to a UInt8 which will be sent to the Arduino. 
//     **********************************************************************************/
// 	ros::Subscriber sub = n.subscribe("cmd_vel", 1, realnavigationCallback);
// 	ros::Subscriber suby = n.subscribe("joy", 1, joystickCallback);
// 	ros::Subscriber subz = n.subscribe("camera/odom", 1, calcSpeedCallback);

//    /**********************************************************************************
//     The advertise() function is how you tell ROS that you want to publish on a given 
//     topic name. This invokes a call to the ROS master node, which keeps a registry of 
//     who is publishing and who is subscribing. After this advertise() call is made, 
//     the master node will notify anyone who is trying to subscribe to this topic name,
//     and they will in turn negotiate a peer-to-peer connection with this node.  
//     advertise() returns a Publisher object which allows you to publish messages on 
//     that topic through a call to publish(). Once all copies of the returned Publisher
//     object are destroyed, the topic will be automatically unadvertised.
   
//     The second parameter to advertise() is the size of the message queue used for
//     publishing messages.  If messages are published more quickly than we can send them,
//     the number here specifies how many messages to buffer up before throwing some away.
//     **********************************************************************************/
// 	ros::Publisher pub = n.advertise<std_msgs::UInt32>("cinnabar", 1000);

// 	ros::Rate loop_rate(runFrequency);

// 	while (ros::ok())
// 	{
// 		ros::spinOnce();

// 		loop_rate.sleep();
// 	}

// 	return 0;
// }