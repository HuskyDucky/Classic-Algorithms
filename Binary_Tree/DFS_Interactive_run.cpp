/**
    File    : DFS_Interactive.cpp
    Author  : Menashe Rosemberg

    Depth First Search - DFS
**/

#include "DFS_Interactive.h"

void Run_BinaryTreeSearch_DFS_Interactive() {

    cout << "\n\t\t\t\tBinary Tree Search - DFS Interactive\n"
         << "\n\nExpected 0, 1, 3, 4, 2, 5, 6, 7";

    vector<EdgeVV> Edges {{0, 1},
                          {0, 2},
                          {1, 3},
                          {1, 4},
                          {2, 5},
                          {2, 6},
                          {6, 7}
    };

    DFS_Interactive DFSInt(Edges);

    DFSInt.ProcessDFS(0);
}
