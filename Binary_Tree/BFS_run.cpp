/**
    File    : BFS_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.02.27            Version: 20190227.1

    Breadth First Search - BFS

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include <iostream>

#include "../_lib_/_Lib_Edge.h"

#include "BFS.h"

using namespace std;

void Run_BinaryTreeSearch_BFS() {

    cout << "\n\t\t\t\tBinary Tree Search - BFS"
         << "\n\nExpected 0, 1, 2, 3, 4, 5, 6, 7\nResult:";

    vector<EdgeVV> Edges {{0, 1},
                          {0, 2},
                          {1, 3},
                          {1, 4},
                          {2, 5},
                          {2, 6},
                          {6, 7}
    };

    BFS bfs(Edges);

    bfs.ProcessBFS(0);
}
