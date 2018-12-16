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

#ifndef INCLUDE_PR2MAID_LEGOBRICK_H_
#define INCLUDE_PR2MAID_LEGOBRICK_H_

#include <geometry_msgs/Pose.h>
#include <string>



/**
 * @brief      Class for lego brick.
 */
class LegoBrick {
 private:
    std::string color_;
    bool isPicked_ = false;
    geometry_msgs::Pose pose_;
 public:
    LegoBrick(geometry_msgs::Pose pose, std::string color);
    LegoBrick();
    geometry_msgs::Pose getPose();
    std::string getColor();
    void changePickStatus(bool pick_status);
    bool getPickStatus();
};

#endif  // INCLUDE_PR2MAID_LEGOBRICK_H_
