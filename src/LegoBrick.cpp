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
* @Last Modified time: 2018-12-15 20:56:30
*/

#include "PR2Maid/LegoBrick.h"



/**
 * @brief      Constructs the object Brick
 *
 * @param[in]  pose   The pose
 * @param[in]  color  The color
 */
LegoBrick::LegoBrick(geometry_msgs::Pose pose, std::string color)
                        :pose_{pose}, color_{color} {}




/**
 * @brief      Gets the pose.
 *
 * @return     The pose.
 */
geometry_msgs::Pose LegoBrick::getPose() { return pose_; }



/**
 * @brief      Gets the color.
 *
 * @return     The color.
 */
std::string LegoBrick::getColor() { return color_; }


/**
 * @brief      Gets the pick status.
 *
 * @return     The pick status.
 */
bool LegoBrick::getPickStatus() { return isPicked_; }



/**
 * @brief      change Brick pick status
 *
 * @param[in]  pick_status  The pick status
 */
void LegoBrick::changePickStatus(bool pick_status) {
    isPicked_ = pick_status;
}
