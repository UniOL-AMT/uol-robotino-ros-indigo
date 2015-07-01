/*
 * DigitalOutputArrayROS.cpp
 *
 *  Created on: 30.06.2015
 *      Author: melvin.isken@uni-oldenburg.de
 *	
 *	Test: rostopic pub -1 /set_digital_values robotino_msgs/DigitalReadings -- '[0, 0]' '[true, false, true, true, false, true, true, true]'
 */

#include "RelayArrayROS.h"

RelayArrayROS::RelayArrayROS()
{
	digital_sub_ = nh_.subscribe("set_relay_values", 1,
			&RelayArrayROS::setRelayValuesCallback, this);
}

RelayArrayROS::~RelayArrayROS()
{
	digital_sub_.shutdown();
}

void RelayArrayROS::setRelayValuesCallback( const robotino_msgs::DigitalReadingsConstPtr& msg)
{
	int numValues = msg->values.size();
	if( numValues > 0 && numValues <3)
	{
		int values[numValues];
		for (int i = 0; i <numValues; i++){
		values[i]=msg->values.at(i);
		
		}
		//memcpy( values, msg->values.data(), numValues * sizeof(bool) );
		setValues( values, numValues );
	}
	else
	{
		ROS_WARN("Warning: Relay Array out of Bounds: %i", numValues);
	}
}
