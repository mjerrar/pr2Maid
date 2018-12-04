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
* @Last Modified time: 2018-12-15 22:33:33
*/
#include <gtest/gtest.h>
#include <ros/ros.h>
#include <string>
#include "../include/PR2Maid/DropBin.h"
#include "geometry_msgs/Pose.h"
#include "../include/PR2Maid/Utils.h"

TEST(DropBinTest, Positive) {
    geometry_msgs::Pose bin_pose;
    bin_pose.position.x = 1;
    bin_pose.position.y = 1;
    bin_pose.position.z = 1;
    bin_pose.orientation.x = 0;
    bin_pose.orientation.y = 0;
    bin_pose.orientation.z = 0;
    bin_pose.orientation.w = 1;

    geometry_msgs::Pose drop_pose;
    drop_pose.position.x = 2;
    drop_pose.position.y = 2;
    drop_pose.position.z = 2;
    drop_pose.orientation.x = 0;
    drop_pose.orientation.y = 0;
    drop_pose.orientation.z = 0;
    drop_pose.orientation.w = 1;

    std::string color = "red";

    DropBin bin(bin_pose, drop_pose, color);

    geometry_msgs::Pose bin_pose_rec;
    geometry_msgs::Pose drop_pose_rec;

    bin_pose_rec = bin.getBinPose();
    drop_pose_rec = bin.getDropPose();

    EXPECT_EQ(comparePose(bin_pose_rec, bin_pose), true);
    EXPECT_EQ(comparePose(drop_pose_rec, drop_pose), true);
    EXPECT_EQ(bin.getColor(), color);

    bin.incrementBricks();
    bin.incrementBricks();

    EXPECT_EQ(bin.getCount(), 2);
}
