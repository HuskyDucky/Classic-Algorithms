/**
    File    : DFS_Interactive.cpp
    Author  : Menashe Rosemberg
    Created : 2019.02.28            Version: 20190228.2

    Depth First Search - DFS Interactive

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
