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

#ifndef INCLUDE_PR2MAID_BRICKLIST_H_
#define INCLUDE_PR2MAID_BRICKLIST_H_

#include <vector>

#include "PR2Maid/LegoBrick.h"

class BrickList {
 private:
    int count_ = 0;
    std::vector<LegoBrick> list_brick_;
 public:
    LegoBrick readBrick();
    LegoBrick popBrick();
    void addBrick(LegoBrick brick);
    void clearList();
    int getCount();
    bool isEmpty();
};

#endif  // INCLUDE_PR2MAID_BRICKLIST_H_
