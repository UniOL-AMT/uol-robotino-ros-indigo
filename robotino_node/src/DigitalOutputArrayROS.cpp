/*
 * DigitalOutputArrayROS.cpp
 *
 *  Created on: 09.12.2011
 *      Author: indorewala@servicerobotics.eu
 *	Edited: melvin.isken@uni-oldenburg.de
 *	
 *	Test: rostopic pub -1 /set_digital_values robotino_msgs/DigitalReadings -- '[0, 0]' '[true, false, true, true, false, true, true, true]'
 */

#include "DigitalOutputArrayROS.h"

DigitalOutputArrayROS::DigitalOutputArrayROS()
{
	digital_sub_ = nh_.subscribe("set_digital_values", 1,
			&DigitalOutputArrayROS::setDigitalValuesCallback, this);
}

DigitalOutputArrayROS::~DigitalOutputArrayROS()
{
	digital_sub_.shutdown();
}

void DigitalOutputArrayROS::setDigitalValuesCallback( const robotino_msgs::DigitalReadingsConstPtr& msg)
{
	int numValues = msg->values.size();
	if( numValues > 0 && numValues <9)
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
		ROS_WARN("Warning: Digital Output Array out of Bounds: %i", numValues);
	}
}
