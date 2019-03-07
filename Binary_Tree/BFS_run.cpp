/**
    File    : BFS_run.cpp
    Author  : Menashe Rosemberg

    Test Breadth First Search - BFS
**/
#include "../_lib_/_Lib_Edge.h"

#include "BFS.h"

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
