/*
 * robotino_local_move_server_node.cpp
 *
 *  Created on: 14.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#include "RobotinoLocalMoveServer.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "robotino_local_move_server_node");
	RobotinoLocalMoveServer rlms;
	rlms.spin();

	return 0;
}
