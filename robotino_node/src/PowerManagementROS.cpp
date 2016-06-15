/*
 * PowerManagementROS.cpp
 *
 *  Created on: 07.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#include "PowerManagementROS.h"

PowerManagementROS::PowerManagementROS()
{
	power_pub_ = nh_.advertise<robotino_msgs::PowerReadings>("power_readings", 1, true);
}

PowerManagementROS::~PowerManagementROS()
{
	power_pub_.shutdown();
}

void PowerManagementROS::setTimeStamp(ros::Time stamp)
{
	stamp_ = stamp;
}

void PowerManagementROS::readingsEvent(float battery_voltage, float system_current, bool ext_power, int num_chargers, const char* batteryType, bool batteryLow, int batteryLowShutdownCounter)
{
	// Build the PowerReadings msg
	power_msg_.stamp = ros::Time::now();
	power_msg_.current = system_current;
	power_msg_.voltage = battery_voltage;

	// Publish the msg
	power_pub_.publish( power_msg_ );
}
