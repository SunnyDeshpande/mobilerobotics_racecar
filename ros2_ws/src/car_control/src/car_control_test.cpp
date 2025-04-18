#include <cmath>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"

using std::placeholders::_1;
bool button_pressed;
bool prev_button_state;

class CarControlNode : public rclcpp::Node
{
public:
    CarControlNode()
    : Node("car_control"), joynavigation(97100),autonavigation(97100), flag(false), timeSinceLastMessage(0.0)
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "joy", 10, std::bind(&CarControlNode::joystickCallback, this, _1));

        cmd_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "cmd_vel", 10, std::bind(&CarControlNode::realNavigationCallback, this, _1));

        odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "camera/odom", 10, std::bind(&CarControlNode::calcSpeedCallback, this, _1));

        publisher_ = this->create_publisher<std_msgs::msg::Int32>("micro_ros_arduino_subscriber", 10);

        //Timer to continously check flag  and publish data

        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&CarControlNode::publishNavigationData, this));
        //timer_ = this->create_wall_timer(std::chrono::milliseconds(static_cast<int>(1000.0/run_frequency)), std::bind(&CarControlNode::publishNavigationData, this));
    }

private:
    void joystickCallback(const sensor_msgs::msg::Joy::SharedPtr msg) 
    {
        //int button = msg->buttons[1];
        //if (button == 1)
        //{
        //    flag = !flag;
        //}

        bool current_button_state = msg->buttons[1]==1;

        if(current_button_state && !prev_button_state && !button_pressed)
        {
            RCLCPP_INFO(this->get_logger(), "Button 0 Pressed once!");
            button_pressed = true;
            flag =!flag;
        }

        else if(!current_button_state && prev_button_state)
        {
            button_pressed = false;

        }

        prev_button_state = current_button_state;

        // Store value here for manipulation (-1 for flipping between forward)
        double frontBackAx = msg->axes[1] * -1;  	
        int steeringJoystickPosition = 97 + (msg->axes[3] * 30);
        int throttleLeverPosition = 100 - (frontBackAx * 15);

        // Emergency brake
        if (msg->axes[5] == -1)
        {
            throttleLeverPosition = 150;
        }

        // For debugging purposes
        throttleLeverPositionGlobal = throttleLeverPosition;
        steeringJoystickPositionGlobal = steeringJoystickPosition;

        //RCLCPP_INFO(this->get_logger(), "throttleLeverPositionGlobal: '%i'", throttleLeverPositionGlobal);
        //RCLCPP_INFO(this->get_logger(), "steeringJoystickPositionGlobal: '%i'", steeringJoystickPositionGlobal);

        // First three digits steering, last three digits throttle
        joynavigation = (steeringJoystickPosition * 1000) + throttleLeverPosition;

        // For debugging purposes	
        // joynavigationGlobal = joynavigation;

        // auto message = std_msgs::msg::Int32();
        // message.data = joynavigation;

        // publisher_->publish(message);
        timeSinceLastMessage = 0.0;
    }

    void realNavigationCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        
        RCLCPP_INFO(this->get_logger(), "flag: '%i'", flag);
        if (!flag)
    {
        double angular_z = msg->angular.z;
        double linear_x = msg->linear.x;	
        angularZprintout = angular_z;
        linearXprintout = msg->linear.x;

        double steering_ratio = 0.0;

  
        
        radius = (linearVelocity > 0.1) ? (linearVelocity/angular_z) : (0.1/angular_z);
        
        steering_angle = atan(wheelbase / radius);
        
        //throttle = 100 + (linear_x / 0.20) * 6;
         // Optimized throttle calculation
        if (linear_x == 0.0)
            throttle = 100;
        else if (fabs(linear_x) >= 0.1 && fabs(linear_x) <= 0.25)
            throttle = (linear_x > 0) ? 104 : 97;
        else if (fabs(linear_x) > 0.25 && fabs(linear_x) <= 0.5)
            throttle = (linear_x > 0) ? 104 : 96;
        else if (fabs(linear_x) > 0.5 && fabs(linear_x) <= 1.0)
            throttle = (linear_x > 0) ? 105 : 95;
        
        steering_ratio = steering_angle / degreesToRadians(30);
        steering_ratio = std::clamp(steering_ratio, -3.0, 3.0);
        int steering_total = static_cast<int>(steering_ratio * 20);
        

        steering = 97 + steering_total;

        autonavigation = (steering*1000) + throttle;
        timeSinceLastMessage = 0.0; 

        RCLCPP_INFO(this->get_logger(), "autonavigation: '%i'", autonavigation);
    }
}

 
  

    void calcSpeedCallback(const nav_msgs::msg::Odometry::SharedPtr odom)
    {
        // Update position array
        for (int row = 0; row < 4; ++row)
        {
            for (int col = 0; col < 5; ++col )
            {
                positionArray[row][col] = positionArray[row][col + 1];
            }
        }

        positionArray[0][5] = odom->pose.pose.position.x;
        positionArray[1][5] = odom->pose.pose.position.y;
        positionArray[2][5] = odom->pose.pose.position.z;

        // Calculate linear displacement
        xPosition = positionArray[0][5];
        yPosition = positionArray[1][5];
        zPosition = positionArray[2][5];
        pythagoreanDistance = sqrt(pow(xPosition, 2) + pow(yPosition, 2) + pow(zPosition, 2));
        positionArray[3][5] = pythagoreanDistance;

        deltaDistance = std::abs(pythagoreanDistance - positionArray[3][0]);

        // Update time array
        for (int row = 0; row < 2; ++row)
        {
            for (int col = 0; col < 5; ++col)
            {
                timeArray[row][col] = timeArray[row][col + 1];
            }
        }

        timeArray[0][5] = odom->header.stamp.sec;
        timeArray[1][5] = odom->header.stamp.nanosec;

        // Calculate time elapsed
        if (timeArray[0][5] == timeArray[0][0])
        {
            deltaNanoseconds = timeArray[1][5] - timeArray[1][0];
        }
        else
        {
            deltaNanoseconds = timeArray[1][5] + 1000000000 - timeArray[1][0];
        }

        deltaTime = deltaNanoseconds / 1e9; // Convert nanoseconds to seconds

        // Calculate linear velocity
        linearVelocity = deltaDistance / deltaTime;
    }


    double degreesToRadians(double angle_in_degree)
    {
        return angle_in_degree * M_PI / 180.0;
    }

    void stopCallback()
    {
        navigation.data = 97100;
    }

    void publishNavigationData()
    {
        timeSinceLastMessage += 1.0 / run_frequency;

        if(flag)
        {
            navigation.data = joynavigation;
        }
        else
        {
            navigation.data = autonavigation;
            if(timeSinceLastMessage > noMessageThreshold)
            {
                RCLCPP_INFO(this->get_logger(), "No joystick message received for too long! Stopping.");
                stopCallback();
            }
        }
        publisher_->publish(navigation);


        
        // RCLCPP_INFO(this->get_logger(), "Published Navigation Data");
        
    }

    


    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    // Global variables
    bool flag = false;
    int throttleLeverPositionGlobal = 0;
    int steeringJoystickPositionGlobal = 0;
    int32_t joynavigationGlobal = 0;
    int32_t joynavigation = 97100;
    int32_t autonavigation = 97100; //
    std_msgs::msg::Int32 navigation;
    double steering_angle;
    double radius;
    double throttle = 100;
    double steering = 90;
    double maxVelocity = 0.5;
    double maxSteering = 0.005;
    double wheelbase = 0.5;
    double angularZprintout = 0;
    double linearXprintout = 0;
    double positionArray[4][6] = {0};
    double xPosition, yPosition, zPosition, pythagoreanDistance, deltaDistance;
    uint32_t timeArray[2][6] = {0};
    uint32_t seconds, nanoseconds, deltaSeconds, deltaNanoseconds;
    const double run_frequency=60.0;
    double deltaTime;
    double linearVelocity = 0;
    const double noMessageThreshold = 0.15;
    double timeSinceLastMessage = noMessageThreshold; // Time in seconds since last joy message received
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<CarControlNode>());

    rclcpp::shutdown();
    return 0;
}
