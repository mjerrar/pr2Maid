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
* @Date:   2018-12-15 20:58:07
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-15 22:11:04
*/
#include <gtest/gtest.h>
#include <ros/ros.h>
#include <string>
#include "../include/PR2Maid/LegoBrick.h"
#include "geometry_msgs/Pose.h"
#include "../include/PR2Maid/Utils.h"

TEST(LegoBrickTest, Positive) {
    geometry_msgs::Pose pose;
    pose.position.x = 1;
    pose.position.y = 1;
    pose.position.z = 1;
    pose.orientation.x = 0;
    pose.orientation.y = 0;
    pose.orientation.z = 0;
    pose.orientation.w = 1;
    std::string color = "red";
    LegoBrick brick(pose, color);
    geometry_msgs::Pose pose_rec;
    pose_rec = brick.getPose();
    EXPECT_EQ(comparePose(pose, pose_rec), true);
    EXPECT_EQ(brick.getColor(), color);
    EXPECT_EQ(brick.getPickStatus(), false);
    brick.changePickStatus(true);
    EXPECT_EQ(brick.getPickStatus(), true);
}
