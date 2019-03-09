/**
    File    : DFS_Interactive_run.cpp
    Author  : Menashe Rosemberg

    Depth First Search - DFS

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/

#include <iostream>

#include "DFS_Interactive.h"

using namespace std;

void Run_BinaryTreeSearch_DFS() {

    cout << "\n\t\t\t\tBinary Tree Search - DFS Interactive\n"
         << "\n\nExpected 0, 1, 3, 4, 2, 5, 6, 7\nResult:";

    vector<EdgeVV> Edges {{0, 1},
                          {0, 2},
                          {1, 3},
                          {1, 4},
                          {2, 5},
                          {2, 6},
                          {6, 7}
    };

    DFS DFSInt(Edges);

    DFSInt.ProcessDFS(0);
}
