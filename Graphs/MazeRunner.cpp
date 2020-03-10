/**
    File    : MazeRunner.cpp
    Author  : Menashe Rosemberg
    Created : 2019.04.02            Version: 20190402.12
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

void Run_MazeRunner_DFS() {
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
                    "WWWWWWWWWWWWWWWWWWW    W W W   W   W W",
                    "W                   WW             W W",
                    "W WWWWWWWWWWWWWWWWW    WWWWWWWWWWW W W",
                    "W W               WWWWWW         W W W",
                    "W W WWWWWWWWWWWWW W    W WWWWWWWWW W W",
                    "W W             W   WW             W W",
                    "W WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW W",
                    "W                                    W",
                    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
                   };

    RunRunner(Maze);
}
