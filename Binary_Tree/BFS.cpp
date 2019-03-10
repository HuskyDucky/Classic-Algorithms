/**
    File    : BFS.cpp
    Author  : Menashe Rosemberg
    Created : 2019.02.27            Version: 20190227.1

    Breadth First Search - BFS

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "BFS.h"

BFS::BFS(vector<EdgeVV>& Edges) : Visited(TotOfVertices(Edges), false),
                                  Vertices(this->Visited.size()) {

    for (auto& edge : Edges)
        Vertices[edge.Vertex_1()].emplace_back(edge.Vertex_2());
}

void BFS::ProcessBFS(VertexType CurrVertex) {
     if (CurrVertex >= Vertices.size())
        throw runtime_error("BFS: Vertex doesn't exist");

     this->Visited[CurrVertex] = true;

     for (;;) {
         for (auto IIt = Vertices[CurrVertex].cbegin(); IIt != Vertices[CurrVertex].cend(); ++IIt)
             if (!this->Visited[*IIt]) {

                cout << "\nVisiting Vertex " << *IIt;

                this->Visited[*IIt] = true;
                this->Pool.push(*IIt);
             }

         if (this->Pool.empty())
            break;
         else {
              CurrVertex = this->Pool.front();
              this->Pool.pop();
         }
     }
}
