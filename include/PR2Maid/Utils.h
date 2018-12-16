/*Copyright (C) 2018  Jerrar Bukhari

This program is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along
with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INCLUDE_PR2MAID_UTILS_H_
#define INCLUDE_PR2MAID_UTILS_H_

#include "geometry_msgs/Pose.h"
#include "PR2Maid/LegoBrick.h"


/**
 * @brief      Helper Utilities for tests
 *
 * @param[in]  pose1  The pose 1
 * @param[in]  pose2  The pose 2
 *
 * @return     true if test is true
 */
bool comparePose(geometry_msgs::Pose pose1,
        geometry_msgs::Pose pose2);
bool compareBrick(LegoBrick brick1, LegoBrick brick2);

#endif  // INCLUDE_PR2MAID_UTILS_H_
