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
* @Date:   2018-12-16 12:10:43
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-16 12:35:37
*/

#ifndef INCLUDE_PR2MAID_GLOBALPLANNER_H_
#define INCLUDE_PR2MAID_GLOBALPLANNER_H_

#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <nav_msgs/Path.h>
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"

typedef actionlib::SimpleActionClient<
            move_base_msgs::MoveBaseAction> MoveBaseClient;

class GlobalPlanner {
 private:
  ros::NodeHandle n_;
  ros::Subscriber planSub_;
  MoveBaseClient ac;
  move_base_msgs::MoveBaseGoal goal_;
  nav_msgs::Path path_;

 public:
  GlobalPlanner(ros::NodeHandle &nh);
  ~GlobalPlanner();
  void planSubCb(const nav_msgs::Path path);
  bool setGoal(move_base_msgs::MoveBaseGoal goal);
  nav_msgs::Path getPath();
};




#endif  // INCLUDE_PR2MAID_GLOBALPLANNER_H_
