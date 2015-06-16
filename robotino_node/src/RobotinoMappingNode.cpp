#include "RobotinoMappingNode.h"

RobotinoMappingNode::RobotinoMappingNode()
	: nh_("~")
{
	nh_.param<std::string>("hostname", hostname_, "127.0.0.1" );

    com_.setName( "Mapping" );

    initModules();
}

RobotinoMappingNode::~RobotinoMappingNode()
{
}

void RobotinoMappingNode::initModules()
{
	com_.setAddress( hostname_.c_str() );

	// Set the ComIds
	mappingRos_.setComId( com_.id() );
	initialPoseROS_.setComId( com_.id() );
	navGoalROS_.setComId( com_.id() );
	
	com_.connectToServer( false );
}

bool RobotinoMappingNode::spin()
{
	ros::Rate loop_rate( 30 );

	while(nh_.ok())
	{
        ros::Time curr_time = ros::Time::now();
        mappingRos_.setTimeStamp(curr_time);

        com_.processEvents();
        ros::spinOnce();
		loop_rate.sleep();
	}
	return true;
}

