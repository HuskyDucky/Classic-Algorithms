/**
    File    : DFS_Interactive.cpp
    Author  : Menashe Rosemberg

    Depth First Search - DFS
**/

#include "DFS_Interactive.h"

void Run_BinaryTreeSearch_DFS_Interactive() {

    cout << "\n\t\t\t\tBinary TRee Search - DFS Interactive\n"
         << "\n\nExpected 0, 1, 3, 4, 2, 5, 6, 7";

    Graph_DFS_Interactive DFSInt(8);
    DFSInt.AddEdge(0, 1);
    DFSInt.AddEdge(0, 2);
    DFSInt.AddEdge(1, 3);
    DFSInt.AddEdge(1, 4);
    DFSInt.AddEdge(2, 5);
    DFSInt.AddEdge(2, 6);
    DFSInt.AddEdge(6, 7);

    DFSInt.dfs(0);
}
