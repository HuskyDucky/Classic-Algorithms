/**
    File    : DFS_Interactive.cpp
    Author  : Menashe Rosemberg
    Created : 2019.02.28            Version: 20190228.2

    Depth First Search - DFS Interactive

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "DFS_Interactive.h"

DFS::DFS(vector<EdgeVV>& Edges) : Visited(TotOfVertices(Edges), false),
                                  Vertices(this->Visited.size()) {
    for (auto& edge : Edges)
        Vertices[edge.Vertex_1()].emplace_back(edge.Vertex_2());
}

void DFS::ProcessDFS(VertexType CurrVertex) {
     if (CurrVertex >= Vertices.size())
        throw runtime_error("DFS: Vertex doesn't exist");

     for (;;) {
         if (!this->Visited[CurrVertex]) {

            cout << "\nVisiting Vertex " << CurrVertex;

            this->Visited[CurrVertex] = true;
            this->Pool.push(CurrVertex);
         }

         bool NOTfound = true;

         for (auto IIt = Vertices[CurrVertex].cbegin(); IIt != Vertices[CurrVertex].cend(); ++IIt)
             if (!this->Visited[*IIt]) {
                CurrVertex = *IIt;
                NOTfound = false;
                break;
            }

         if (NOTfound) {
            this->Pool.pop();
            if (this->Pool.empty())
                break;

            CurrVertex = this->Pool.top();
         }
     }
}
