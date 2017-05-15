// Copyright 2017 Geoffrey Biggs

#include <ros/ros.h>
#include <rsj_tutorial_2017_ros_basics/Greeting.h>

#include <iostream>

void callback(const rsj_tutorial_2017_ros_basics::Greeting::ConstPtr &msg) {
  std::cout << msg->hello_text << " " << msg->world_name << '\n';
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "Displayer");
  ros::NodeHandle node;

  ros::Subscriber sub = node.subscribe("greeting", 10, callback);

  ros::spin();

  return 0;
}
