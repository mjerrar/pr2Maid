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
* @Date:   2018-12-15 16:46:30
* @Last Modified by:   Jerrar Bukhari
* @Last Modified time: 2018-12-15 23:27:15
*/

#include "PR2Maid/BrickList.h"


/**
 * @brief      Reads a brick for list.
 *
 * @return     read a brick from the list without popping
 */
LegoBrick BrickList::readBrick() {
    return list_brick_.at(list_brick_.size()-1);
}


/**
 * @brief      read the brick from the list
 *
 * @return     pops the brick from the list
 */
LegoBrick BrickList::popBrick() {
    LegoBrick brick = list_brick_.at(list_brick_.size()-1);
    list_brick_.pop_back();
    count_--;
    return brick;
}


/**
 * @brief      Adds a brick.
 *
 * @param[in]  brick  The brick
 */
void BrickList::addBrick(LegoBrick brick) {
    list_brick_.push_back(brick);
    count_++;
}


/**
 * @brief      Empty Brick list contents
 */
void BrickList::clearList() {
    list_brick_.clear();
    count_ = 0;
}


/**
 * @brief      Gets the count.
 *
 * @return     The count.
 */
int BrickList::getCount() {
    return list_brick_.size();
}


/**
 * @brief      Determines if empty.
 *
 * @return     True if empty, False otherwise.
 */
bool BrickList::isEmpty() {
    return list_brick_.empty();
}


