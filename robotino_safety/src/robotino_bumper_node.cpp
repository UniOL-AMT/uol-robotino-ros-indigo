/*
 * robotino_bumper_node.cpp
 *
 *  Created on: Jul 02, 2015
 *      Author: melvin.isken@uni-oldenburg.de
 */

#include <ros/ros.h>


#include <std_msgs/Bool.h>
//#include <tf/transform_listener.h>

void bumperCallback(const std_msgs::BoolConstPtr& msg)
{
	if( msg->data )
	{
		ROS_ERROR("Bumper hit!");
		//ros::shutdown();
		return;
	}
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "robotino_bumper_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(5);

	ros::Subscriber bumper_sub_ = n.subscribe("/bumper", 1, bumperCallback);

	while (ros::ok())
	  {


	    //ROS_INFO("%s", msg.data.c_str());



	    ros::spinOnce();

	    loop_rate.sleep();
	  }

	return 0;
}

