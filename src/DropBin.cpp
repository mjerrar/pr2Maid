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
* @Date:   2018-12-15 16:15:08
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-15 22:33:20
*/

#include "PR2Maid/DropBin.h"

DropBin::DropBin(geometry_msgs::Pose pose, geometry_msgs::Pose drop_pose,
                std::string color):
                bin_pose_{pose}, drop_pose_{drop_pose}, color_{color} {}

geometry_msgs::Pose DropBin::getBinPose () { return bin_pose_; }
geometry_msgs::Pose DropBin::getDropPose () { return drop_pose_; }

std::string DropBin::getColor() { return color_; }
int DropBin::getCount() { return count_; }

void DropBin::incrementBricks() { count_++; }
