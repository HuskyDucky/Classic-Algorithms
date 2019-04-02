/**
    File    : MazeRunner.cpp
    Author  : Menashe Rosemberg
    Created : 2019.04.02            Version: 20190402.1

    Check all spaces reachable in a maze from a random start place

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "MazeRunner.h"
#include "MazeRunner_Running.h"

void Run_MazeRunner() {
    MazeMap Maze = {
                    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
                    "W     WWW   W      W         W       W",
                    "W WW  W     W WWW WWWW WWWWW W WWWW  W",
                    "W           W  W    W   W    W W  W  W",
                    "WWWWWWWWWW          W   WWWW W    W  W",
                    "W          W W  W             WWWWWW W",
                    "WWWWWW W WW  W  W  WWWW WWW          W",
                    "W   W     W  W  W  WWWW W W W W WWWW W",
                    "W   WWWW  W  W     W    W   W W    W W",
                    "W   W     W     W  WWWW W W WWW WWWW W",
                    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
                   };

    RunRunner(Maze);
}
