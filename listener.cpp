#include "ros/ros.h"
#include "practice_cpp/MyProperty.h"

void chatterCallback(const practice_cpp::MyProperty::ConstPtr& msg)
{
  ROS_INFO("I heard: Name=%s, Class=%d", msg->name.c_str(), msg->class);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::spin();

  return 0;
}