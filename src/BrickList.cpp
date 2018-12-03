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
* @Last Modified time: 2018-12-15 17:31:04
*/

#include "PR2Maid/BrickList.h"

LegoBrick BrickList::readBrick() {
    return list_brick_.at(list_brick_.size());
}

LegoBrick BrickList::popBrick() {
    LegoBrick brick = list_brick_.at(list_brick_.size());
    list_brick_.pop_back();
    return brick;
}

void BrickList::addBrick(LegoBrick brick) { list_brick_.push_back(brick); }

void BrickList::clearList() {
    list_brick_.clear();
}

int BrickList::getCount() {
    return list_brick_.size();
}

bool BrickList::isEmpty() {
    return list_brick_.empty();
}


