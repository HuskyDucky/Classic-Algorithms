/**
    File    : MazeRunner_Running.h
    Author  : Menashe Rosemberg
    Created : 2019.04.02            Version: 20190402.1

    Check all spaces reachable in a maze from a random start place

    BSD License

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
