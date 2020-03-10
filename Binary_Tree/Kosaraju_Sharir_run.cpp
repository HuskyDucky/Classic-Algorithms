/**
    File    : Kosaraju_Sharir_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190310.1

    Binary Tree Search - DFS - Strong Connected Component - Kosaraju-Sharir

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
#include <iostream>

#include "Kosaraju_Sharir.h"

void Run_BinaryTreeSearch_DFS_Strong_Connected_Kosaraju_Sharir() {

    cout << "\n\t\t\t\tBinary Tree Search - Kosaraju_Sharir"
         << "\n\tExpected:"
         << "\n0 2 1 3"
         << "\n6 4 5"
         << "\n7"
         << "\n9 8"
         <<"\n\n\tResult:\n";

    vector<EdgeVV> Edges {  {0,1}, {0,3},
                            {1,2}, {1,4},
                            {2,0}, {2,6},
                            {3,2},
                            {4,5}, {4,6},
                            {5,6}, {5,7}, {5,8}, {5,9},
                            {6,4},
                            {7,9},
                            {8,9},
                            {9,8}
    };


    Kosaraju_Sharir T(Edges);

    T.SCC();
}
