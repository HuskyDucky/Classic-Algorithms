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

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;

struct DFS_Interactive {
       DFS_Interactive(vector<EdgeVV>& Edges);

    void ProcessDFS(VertexType CurrVertex);

    private:
        stack<VertexType> Pool;
        vector<list<VertexType>> Vertices;
};

#endif // DFS_H
