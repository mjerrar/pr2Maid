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
* @Date:   2018-12-16 18:55:14
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-16 10:59:20
*/

#ifndef INCLUDE_PR2MAID_LOCALPLANNER_H_
#define INCLUDE_PR2MAID_LOCALPLANNER_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <tf/transform_listener.h>



/**
 * @brief      Class for local planner.
 */
class LocalPlanner {
 private:
  ros::NodeHandle nh_;
  ros::Publisher cmd_vel_pub_;
  tf::TransformListener listener_;
 public:
  LocalPlanner(ros::NodeHandle nh);
  bool Drive(geometry_msgs::Pose nextPose);
};

#endif  // INCLUDE_PR2MAID_LOCALPLANNER_H_
