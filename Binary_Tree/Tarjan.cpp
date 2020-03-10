/**
    File    : Tarjan.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.09            Version: 20190309.1

    Binary Tree Search - DFS - Strong Connected Component - Tarjan

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
#include "Tarjan.h"

Tarjan::Tarjan(vector<EdgeVV>& Edges) : DFS(Edges),
                                        IniCycle(DFS::Vertices.size(), NOT_Visited),
                                        FinCycle(DFS::Vertices.size(), NOT_Visited) {}

void Tarjan::ProcessSCC() {
     for (VertexType Vertex = 0; Vertex < DFS::Vertices.size(); ++Vertex)
         if (this->FinCycle[Vertex] == NOT_Visited)
            SCC(Vertex);

     //Clean up aux variables (not necessary for this example
     //this->QOfComponents = 0;
     //this->IniCycle.assign(this->IniCycle.size(), NOT_Visited);
     //this->FinCycle.assign(this->FinCycle.size(), NOT_Visited);
}

void Tarjan::SCC(VertexType Vertex) {
     this->IniCycle[Vertex] = this->FinCycle[Vertex] =  ++this->QOfComponents;
     DFS::Visited[Vertex] = true;
     DFS::Pool.push(Vertex);

     for (auto IIt = DFS::Vertices[Vertex].cbegin(); IIt != DFS::Vertices[Vertex].cend(); ++IIt) {
         VertexType CurrVertex = *IIt;

         if (this->FinCycle[CurrVertex] == NOT_Visited) {
            SCC(CurrVertex);                                                                     //update CurrVertex as visited
            this->IniCycle[Vertex] = min(this->IniCycle[Vertex], this->IniCycle[CurrVertex]);    //update the candidate to start of cycle
         } else if (DFS::Visited[CurrVertex])
                this->IniCycle[Vertex] = min(this->IniCycle[Vertex], this->FinCycle[CurrVertex]);//update the candidate to finish of cycle (accessed only when this
     }                                                                                           //  function is accessed recursively

     if (this->IniCycle[Vertex] == this->FinCycle[Vertex]) { //it has a cycle (connection)
        while (DFS::Pool.top() != Vertex) {                 //clean up Pool and Visited
              auto ConnVertex =  DFS::Pool.top();
              DFS::Visited[ConnVertex] = false;
              DFS::Pool.pop();

              cout << ConnVertex << ' ';
        }

        auto ConnVertex = DFS::Pool.top();                  //Finish clean up Pool and visited
        DFS::Visited[ConnVertex] = false;
        DFS::Pool.pop();

        cout << ConnVertex << '\n';
     }
}
