/**
    File    : MazeRunner_Running_Show.cpp
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
     cout << endl;

     this_thread::sleep_for(0.04s);
}
