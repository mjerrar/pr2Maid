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
* @Date:   2018-12-15 21:32:40
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-15 23:08:45
*/

#include "PR2Maid/Utils.h"

bool comparePose(geometry_msgs::Pose pose1,
        geometry_msgs::Pose pose2) {
    if ((pose1.position.x == pose2.position.x) &&
        (pose1.position.y == pose2.position.y) &&
        (pose1.position.z == pose2.position.z) &&
        (pose1.orientation.x == pose2.orientation.x) &&
        (pose1.orientation.y == pose2.orientation.y) &&
        (pose1.orientation.z == pose2.orientation.z) &&
        (pose1.orientation.w == pose2.orientation.w)) {
        return true;
    } else {
        return false;
    }
}

bool compareBrick(LegoBrick brick1, LegoBrick brick2) {
    if ( comparePose(brick1.getPose(), brick2.getPose()) &&
        (brick1.getColor() == brick2.getColor()) &&
        (brick1.getPickStatus() == brick2.getPickStatus())) {
        return true;
    } else {
        return false;
    }
}

