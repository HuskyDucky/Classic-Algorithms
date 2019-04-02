/**
    File    : MazeRunner_Running.h
    Author  : Menashe Rosemberg
    Created : 2019.04.02            Version: 20190402.1

    Check all spaces reachable in a maze from a random start place

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef RUNNING_H
#define RUNNING_H

#include <limits>
#include <stack>

#include "MazeRunner.h"

constexpr uint16_t SPACE = ' ';
constexpr uint16_t WALL  = numeric_limits<uint16_t>::max();

namespace Turn {
          constexpr uint8_t UP = 0b0001;
          constexpr uint8_t DW = 0b0010;
          constexpr uint8_t LF = 0b0100;
          constexpr uint8_t RT = 0b1000;

          constexpr uint8_t UK = 0b0000;
          constexpr uint8_t NW = 0b1111;
}

using LinCol    = pair<uint16_t, uint16_t>;
using ImageMaze = vector<vector<uint16_t>>;

void RunRunner(MazeMap& Maze);

#endif // RUNNING_H
