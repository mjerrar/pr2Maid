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

#ifndef INCLUDE_PR2MAID_DROPBIN_H_
#define INCLUDE_PR2MAID_DROPBIN_H_

#include <string>
#include "geometry_msgs/Pose.h"

class DropBin {
 private:
    std::string color_;
    int count_ = 0;
    geometry_msgs::Pose bin_pose_;
    geometry_msgs::Pose drop_pose_;
 public:
    DropBin(geometry_msgs::Pose bin_pose,
    geometry_msgs::Pose drop_pose, std::string color_);
    geometry_msgs::Pose getDropPose();
    geometry_msgs::Pose getBinPose();
    std::string getColor();
    int getCount();
    void incrementBricks();
};

#endif  // INCLUDE_PR2MAID_DROPBIN_H_
