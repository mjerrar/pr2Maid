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

#include "PR2Maid/GlobalPlanner.h"
#include <iostream>

GlobalPlanner::GlobalPlanner(ros::NodeHandle &nh):ac("move_base", true) {
  planSub_ = n_.subscribe("move_base_node/NavfnROS/plan", 1,
                          &GlobalPlanner::planSubCb, this);
}

bool GlobalPlanner::setGoal(move_base_msgs::MoveBaseGoal goal) {
  goal.target_pose.header.frame_id = "base_link";
  goal.target_pose.header.stamp = ros::Time::now();
  ROS_INFO("Sending goal");
  ac.waitForServer();
  ac.sendGoal(goal);
  return true;
}

void GlobalPlanner::planSubCb(const nav_msgs::Path path) {
  path_.header = path.header;
  std::cout<<path.poses[0].pose.position.x;
  for (auto i : path.poses) {
    path_.poses.push_back(i);
  }
}

nav_msgs::Path GlobalPlanner::getPath() {
  return path_;
}

GlobalPlanner::~GlobalPlanner() {}
  

  //ac.waitForResult();

  //if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  //  ROS_INFO("Hooray, the base moved 1 meter forward");
  //else
  //  ROS_INFO("The base failed to move forward 1 meter for some reason");
