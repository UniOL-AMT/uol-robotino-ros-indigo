/*
 * DigitalOutputArrayROS.h
 *
 *  Created on: 30.06.2015
 *      Author: melvin.isken@uni-oldenburg.de
 */

#ifndef RELAYARRAYROS_H_
#define RELAYARRAYROS_H_

#include "rec/robotino/api2/RelayArray.h"

#include <ros/ros.h>
#include "robotino_msgs/DigitalReadings.h"

class RelayArrayROS: public rec::robotino::api2::RelayArray
{
public:
	RelayArrayROS();
	~RelayArrayROS();

private:
	ros::NodeHandle nh_;

	ros::Subscriber digital_sub_;

	void setRelayValuesCallback( const robotino_msgs::DigitalReadingsConstPtr& msg);

};

#endif /* RELAYARRAYROS_H_ */
