/**
    File    : DFS.h
    Author  : Menashe Rosemberg

    Test Breadth First Search - BFS
**/
#ifndef BFS_H
#define BFS_H

#include <iostream>

#include <list>
#include <queue>
#include <vector>

using namespace std;

struct Graph_BFS {
       Graph_BFS(uint32_t v);

    void AddEdge(uint32_t v1, uint32_t v2);
    void bfs(uint32_t v);

    private:
        uint32_t V;
        queue<uint32_t> Pool;
        vector<list<uint32_t>> Adj;
};

#endif // BFS_H
