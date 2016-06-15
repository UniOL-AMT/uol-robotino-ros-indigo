/*
 * PowerManagementROS.h
 *
 *  Created on: 07.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#ifndef POWERMANAGEMENTROS_H_
#define POWERMANAGEMENTROS_H_

#include "rec/robotino/api2/PowerManagement.h"

#include <ros/ros.h>
#include "robotino_msgs/PowerReadings.h"

class PowerManagementROS: public rec::robotino::api2::PowerManagement
{
public:
	PowerManagementROS();
	~PowerManagementROS();

	void setTimeStamp(ros::Time stamp);

private:
	ros::NodeHandle nh_;
	ros::Publisher power_pub_;

	robotino_msgs::PowerReadings power_msg_;

	ros::Time stamp_;

	//void readingsEvent(float current, float voltage);
	void readingsEvent(float battery_voltage, float system_current, bool ext_power, int num_chargers, const char* batteryType, bool batteryLow, int batteryLowShutdownCounter);
};
#endif /* POWERMANAGEMENTROS_H_ */
