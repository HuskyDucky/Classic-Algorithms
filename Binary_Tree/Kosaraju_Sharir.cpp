/**
    File    : Kosaraju_Sharir.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190310.1

    Binary Tree Search - DFS - Strong Connected Component - Kosaraju-Sharir

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Kosaraju_Sharir.h"

Kosaraju_Sharir::Kosaraju_Sharir(vector<EdgeVV>& Edges) : DFS_KS(Edges) {}

Kosaraju_Sharir::Kosaraju_Sharir(vector<list<VertexType>>& DVertices) : DFS_KS(vector<EdgeVV>()) {

    DFS_KS::Vertices.assign(DVertices.size(), {});

    for (VertexType VertexOri = 0; VertexOri < DFS_KS::Vertices.size();++VertexOri)
        for (auto VertexDes = DVertices[VertexOri].begin(); VertexDes != DVertices[VertexOri].end();++VertexDes)
            DFS_KS::Vertices[*VertexDes].push_back(VertexOri); //Reverse the graph
}

void Kosaraju_Sharir::SCC() {
    for (VertexType Vertex = 0; Vertex < Visited.size(); ++Vertex)
        if (!DFS_KS::Visited[Vertex])
           this->FillPool_DFS_Ordered(Vertex, DFS_KS::Visited, DFS_KS::Pool);    //1st DFS

    fill(DFS_KS::Visited.begin(), DFS_KS::Visited.end(), false);    //Reset visited to be used by the 2nd DFS

    Kosaraju_Sharir Kosh(this->Vertices);   //Reverse the graph

    while (!DFS_KS::Pool.empty()) {
          VertexType Vertex = DFS_KS::Pool.top();
          DFS_KS::Pool.pop();

          // Print Strongly connected component of the popped vertex
          if (!DFS_KS::Visited[Vertex]) {
                Kosh.ProcessSCC(Vertex, DFS_KS::Visited);
                cout << endl;
          }
    }
}

void Kosaraju_Sharir::ProcessSCC(VertexType CurrVertex, vector<uint8_t>& visited) {
     visited[CurrVertex] = true;
     cout << CurrVertex << ' ';                     //Print the vertex member of current cycle

     for (auto Vertex = DFS_KS::Vertices[CurrVertex].begin(); Vertex != DFS_KS::Vertices[CurrVertex].end(); ++Vertex)
         if (!visited[*Vertex])
            this->ProcessSCC(*Vertex, visited);     //Find all vertices to this cycle (connected to CurrVertex)
}

void Kosaraju_Sharir::FillPool_DFS_Ordered(VertexType CurrVertex, vector<uint8_t>& visited, stack<VertexType>& pool) {
     visited[CurrVertex] = true;

     for (auto Vertex  = DFS_KS::Vertices[CurrVertex].begin(); Vertex != DFS_KS::Vertices[CurrVertex].end(); ++Vertex)
         if (!visited[*Vertex])
            this->FillPool_DFS_Ordered(*Vertex, visited, pool);

     pool.push(CurrVertex); //All vertices reachable from CurrVertex are processed by now
}

