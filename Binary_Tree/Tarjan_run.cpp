/**
    File    : Tarjan_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.09            Version: 20190309.1

    Binary Tree Search - DFS - Strong Connected Component - Tarjan

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

#include "Tarjan.h"

void Run_BinaryTreeSearch_DFS_Strong_Connected_Tarjan() {

    cout << "\n\t\t\t\tBinary Tree Search - Tarjan"
         << "\n\tExpected:"
         << "\n8 9"
         << "\n7"
         << "\n5 4 6"
         << "\n3 2 1 0"
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

    Tarjan T(Edges);

    T.ProcessSCC();
}
