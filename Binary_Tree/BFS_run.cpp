/**
    File    : BFS-run.cpp
    Author  : Menashe Rosemberg

    Test Breadth First Search - BFS
**/

#include "BFS.h"

void Run_BinaryTreeSearch_BFS() {

    cout << "\n\t\t\t\tBinary Tree Search - BFS"
         << "\n\nExpected 0, 1, 2, 3, 4, 5, 6, 7";

    Graph_BFS bfs(8);
    bfs.AddEdge(0, 1);
    bfs.AddEdge(0, 2);
    bfs.AddEdge(1, 3);
    bfs.AddEdge(1, 4);
    bfs.AddEdge(2, 5);
    bfs.AddEdge(2, 6);
    bfs.AddEdge(6, 7);

    bfs.bfs(0);
}
