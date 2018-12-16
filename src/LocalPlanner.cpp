/**
 * Copyright (C) 2018  Jerrar Bukhari
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
* @Author: Jerrar Bukhari
* @Date:   2018-12-15 19:04:19
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-16 06:59:35
*/


#include "PR2Maid/LocalPlanner.h"
#include "PR2Maid/GlobalPlanner.h"
#include "tf/tf.h"
#include  "tf/transform_broadcaster.h"


/**
 * @brief      Constructs the object Local Planner.
 *
 * @param[in]  nh    ROS node handle
 */
LocalPlanner::LocalPlanner(ros::NodeHandle nh):nh_(nh) {
  // set up the publisher for the cmd_vel topic
  cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 1);
}


/**
 * @brief Drive forward a specified distance based on odometry information
 *
 * @param[in]  nextMapPose  The next map pose
 *
 * @return     { description_of_the_return_value }
 */
bool LocalPlanner::Drive(geometry_msgs::Pose nextMapPose) {
  // wait for the listener to get the first message
  listener_.waitForTransform("base_footprint", "map",
                             ros::Time(0), ros::Duration(1.0));

  // we will record transforms here
  tf::StampedTransform start_transform;
  tf::StampedTransform current_transform;

  // record the starting transform from the odometry to the base frame
  listener_.lookupTransform("base_footprint", "map",
                            ros::Time(0), start_transform);

  geometry_msgs::Twist vel_msgs;
  vel_msgs.angular.z = 4 * atan2(start_transform.getOrigin().y(),
                                  start_transform.getOrigin().x());
  vel_msgs.linear.x = 0.5 * sqrt(pow(start_transform.getOrigin().x(), 2)+
                                pow(start_transform.getOrigin().y(), 2));
  ros::Rate rate(10.0);
  bool done = false;
  while (!done && nh_.ok()) {
    // send the drive command
    cmd_vel_pub_.publish(vel_msgs);
    rate.sleep();
    // get the current transform
    try {
      listener_.lookupTransform("base_footprint", "map",
                                ros::Time(0), current_transform);
    } catch (tf::TransformException& ex) {
      ROS_ERROR("%s", ex.what());
      break;
    }
    // see how far we've traveled
    tf::Transform relative_transform =
        start_transform.inverse() * current_transform;
    double dist_moved = relative_transform.getOrigin().length();

    if (dist_moved >2) done = true;
    ROS_INFO_STREAM(vel_msgs.angular.z);
  }
  if (done) return true;
  return false;
}
