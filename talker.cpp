#include "ros/ros.h"
#include "practice_cpp/MyProperty.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<practice_cpp::MyProperty>("chatter", 1000);
  ros::Rate loop_rate(1);

  practice_cpp::MyProperty msg;
  msg.name = "Student";
  msg.class = 2023;

  while (ros::ok())
  {
    ROS_INFO("Published: name = %s, class = %d", msg.name.c_str(), msg.class);
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}