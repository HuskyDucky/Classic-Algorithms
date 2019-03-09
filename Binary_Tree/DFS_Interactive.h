/**
    File    : DFS_Interactive.h
    Author  : Menashe Rosemberg

    Breadth First Search - BFS

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef DFS_H
#define DFS_H

#include <iostream>

#include <list>
#include <stack>
#include <vector>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;

struct DFS {
       DFS(vector<EdgeVV>& Edges);

    void ProcessDFS(VertexType CurrVertex);

    protected:
        vector<uint8_t> Visited;
        vector<list<VertexType>> Vertices;

        stack<VertexType> Pool;
};

#endif // DFS_H
