/**
    File    : BFS.h
    Author  : Menashe Rosemberg
    Created : 2019.02.27            Version: 20190227.1

    Breadth First Search - BFS

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef BFS_H
#define BFS_H

#include <iostream>

#include <list>
#include <queue>
#include <vector>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;

struct BFS {
       BFS(vector<EdgeVV>& Edges);

    void ProcessBFS(VertexType CurrVertex);

    protected:
        vector<uint8_t> Visited;
        vector<list<VertexType>> Vertices;

        queue<VertexType> Pool;
};

#endif // BFS_H
