/**
    File    : Kosaraju_Sharir.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190310.1

    Binary Tree Search - DFS - Strong Connected Component - Kosaraju-Sharir

    BSD License

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

