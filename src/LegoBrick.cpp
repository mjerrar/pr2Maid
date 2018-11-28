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
* @Date:   2018-12-15 15:50:01
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-15 16:23:08
*/

#include "PR2Maid/LegoBrick.h"

LegoBrick::LegoBrick(geometry_msgs::Pose pose, std::string color)
                        :pose_{pose}, color_{color} {}

geometry_msgs::Pose LegoBrick::getPose() { return pose_; }

std::string LegoBrick::getColor() { return color_; }

void LegoBrick::changePickStatus(bool pick_status) {
    isPicked_ = pick_status;
}
