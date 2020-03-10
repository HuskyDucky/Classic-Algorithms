/**
    File    : MazeRunner_Running.cpp
    Author  : Menashe Rosemberg
    Created : 2019.04.02            Version: 20190404.1

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
#include "MazeRunner.h"
#include "MazeRunner_Running.h"
#include "MazeRunner_Running_Show.h"

static void CheckEmptySpaces(const ImageMaze& Maze) {
       for (ImageMaze::size_type Lin = 0; Lin < Maze.size(); ++Lin)
            for (vector<uint16_t>::size_type Col = 0; Col < Maze[Lin].size(); ++Col)
                if (Maze[Lin][Col] == 0) {
                    cerr << "\nThis map has unreachable places\n\n";
                    return;
                }
}

ImageMaze CreateImageMaze(const MazeMap& oMaze) {
          ImageMaze Maze(oMaze.size());

          for (MazeMap::size_type Lin = 0; Lin < oMaze.size(); ++Lin)
              for (string::size_type Col = 0; Col < oMaze[Lin].size(); ++Col)
                  Maze[Lin].emplace_back(oMaze[Lin][Col] == 'W' ?
                                         numeric_limits<uint16_t>::max() : 0 );

          return Maze;
}

static ImageMaze Run(MazeMap& oMaze) {
       ImageMaze Maze = CreateImageMaze(oMaze);

       uint16_t Lin = 0;
       uint16_t Col = 0;

       while (Lin < Maze.size()) {
             if (Maze[Lin][Col] == 0) break;

             if (++Col == Maze[Lin].size())
                 ++Lin,
                 Col=0;
       }

       stack<LinCol> Visited;
       Visited.emplace(Lin, Col);
       Maze[Lin][Col] = Turn::UP + Turn::LF;

       for (;;) {
           if (~Maze[Lin][Col] &  Turn::RT) {
                Maze[Lin][Col] += Turn::RT;
                  if (Col != Maze[0].size()-1 &&
                      Maze[Lin][Col+1] != WALL)
                      Maze[Lin][++Col] += Turn::LF;

           } else if (~Maze[Lin][Col] &  Turn::DW) {
                       Maze[Lin][Col] += Turn::DW;
                       if (Lin != Maze.size()-1 &&
                           Maze[Lin+1][Col] != WALL)
                           Maze[++Lin][Col] += Turn::UP;

           } else if (~Maze[Lin][Col] &  Turn::UP) {
                       Maze[Lin][Col] += Turn::UP;
                       if (Lin != 0  &&
                           Maze[Lin-1][Col] != WALL)
                           Maze[--Lin][Col] += Turn::DW;

           } else if (~Maze[Lin][Col] &  Turn::LF) {
                       Maze[Lin][Col] += Turn::LF;
                       if (Col != 0 &&
                           Maze[Lin][Col-1] != WALL)
                           Maze[Lin][--Col] += Turn::RT;
           }

           if (Lin != Visited.top().first || Col != Visited.top().second)
               Visited.emplace(Lin, Col);

           while (Maze[Visited.top().first][Visited.top().second] == Turn::NW) {
                 Visited.pop();
                 if (Visited.size()) {
                    Lin = Visited.top().first;
                    Col = Visited.top().second;
                 } else //{
                 //   CheckEmptySpaces(Maze);
                    return Maze;
                 //}
           }

           Show(Maze);
       }
}

void RunRunner(MazeMap& oMaze) {
     CheckEmptySpaces(Run(oMaze));
}
