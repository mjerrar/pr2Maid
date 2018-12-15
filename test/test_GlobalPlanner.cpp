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
* @Date:   2018-12-16 14:21:49
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-16 16:12:47
*/


#include <gtest/gtest.h>
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <string>
#include "PR2Maid/GlobalPlanner.h"
#include "nav_msgs/Path.h"
#include "../include/PR2Maid/GlobalPlanner.h"

TEST(GlobalPlanarTest, Positive) {
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "fake_id";
    ros::NodeHandle nh;
    GlobalPlanner planner(nh);

    bool success = planner.setGoal(goal);

    EXPECT_EQ(success, 1);

    nav_msgs::Path path_rec = planner.getPath();
    EXPECT_EQ(goal.target_pose.header.frame_id ==
                 path_rec.header.frame_id, false);

    EXPECT_EQ(planner.getPath().poses.size(), 0);
}
