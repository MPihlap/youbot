#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sstream>
#include "std_msgs/String.h"

ros::Publisher chatter_pub;

void cmd_vel_callback(const geometry_msgs::Twist& vel_cmd)
{ 

  //   ROS_INFO("I heard x: [%f]", vel_cmd.linear.x);
    // ROS_INFO("I heard y: [%f]", vel_cmd.linear.y);
   // ROS_INFO("I heard z: [%f]", vel_cmd.linear.z);

     std_msgs::String msg;

     std::stringstream ss;     

     if(vel_cmd.linear.x == 2)
     {
	ros::Rate rate(10);
   	ss << "forward";
   	msg.data = ss.str();
  	//ROS_INFO("%s", msg.data.c_str());
   	chatter_pub.publish(msg);
	rate.sleep();
     } 

     if(vel_cmd.linear.x == -2)
     {
	ros::Rate rate(10);
   	ss << "backward";
   	msg.data = ss.str();
  	//ROS_INFO("%s", msg.data.c_str());
   	chatter_pub.publish(msg);
	rate.sleep();
     } 

     if(vel_cmd.angular.z == 2)
     {
	ros::Rate rate(10);
   	ss << "left";
   	msg.data = ss.str();
  	//ROS_INFO("%s", msg.data.c_str());
   	chatter_pub.publish(msg);
	rate.sleep();
     } 

     if(vel_cmd.angular.z == -2)
     {
	ros::Rate rate(10);
   	ss << "right";
   	msg.data = ss.str();
  	//ROS_INFO("%s", msg.data.c_str());
   	chatter_pub.publish(msg);
	rate.sleep();
     } 
}


int main( int argc, char* argv[] )
{
ros::init(argc, argv, "test_talker" );

ros::NodeHandle n;
ros::Subscriber sub = n.subscribe("turtle1/cmd_vel", 1, cmd_vel_callback);

chatter_pub = n.advertise<std_msgs::String>("leap_dir", 1);



while( n.ok() ) 
{
    ros::spin();
}

return 1;
}