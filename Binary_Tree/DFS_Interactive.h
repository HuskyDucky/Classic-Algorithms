/**
    File    : DFS_Interactive.h
    Author  : Menashe Rosemberg

    Breadth First Search - BFS
**/
#ifndef DFS_H
#define DFS_H

#include <iostream>

#include <list>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph_DFS_Interactive {
       Graph_DFS_Interactive(uint32_t v);

    void AddEdge(uint32_t v1, uint32_t v2);
    void dfs(uint32_t v);

    private:
        uint32_t V;
        stack<uint32_t> S;
        vector<list<uint32_t>> Adj;
};

#endif // DFS_H
