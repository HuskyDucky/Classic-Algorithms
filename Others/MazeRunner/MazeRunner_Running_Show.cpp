/**
    File    : MazeRunner_Running_Show.cpp
    Author  : Menashe Rosemberg
    Created : 2019.04.02            Version: 20190402.1

    Check all spaces reachable in a maze from a random start place

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "MazeRunner_Running_Show.h"

void Show(const ImageMaze& Maze) {
     for (vector<uint16_t>::size_type Lin = 0; Lin < Maze.size(); ++Lin) {
         cout << '\n';
         for (string::size_type Col = 0; Col < Maze[Lin].size(); ++Col)
             if (Maze[Lin][Col] == WALL)
                cout << 'W';
             else if (Maze[Lin][Col] == Turn::NW)
                     cout << '.';
             else if (Maze[Lin][Col] != Turn::UK)
                     cout << '+';
             else
                     cout << ' ';
     }
     cout << flush;

     this_thread::sleep_for(0.04s);
}
