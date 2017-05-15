// Copyright 2017 Geoffrey Biggs

#include <ros/ros.h>
#include <rsj_tutorial_2017_ros_basics/Greeting.h>

#include <string>

int main(int argc, char **argv) {
  ros::init(argc, argv, "Greeter");
  ros::NodeHandle node;

  std::string hello_text;
  std::string world_name;
  ros::param::param<std::string>("~hello_text", hello_text, "hello");
  ros::param::param<std::string>("~world_name", world_name, "world");

  ros::Publisher pub = node.advertise<rsj_tutorial_2017_ros_basics::Greeting>("greeting", 1);

  ros::Rate rate(1);

  while (ros::ok()) {
    ros::spinOnce();

    ROS_INFO("Publishing greeting '%s %s'", hello_text.c_str(), world_name.c_str());
    rsj_tutorial_2017_ros_basics::Greeting greeting;
    greeting.hello_text = hello_text;
    greeting.world_name = world_name;
    pub.publish(greeting);

    rate.sleep();
  }

  return 0;
}
