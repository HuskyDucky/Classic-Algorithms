/**
    File    : Tarjan.cpp
    Author  : Menashe Rosemberg

    Binary Tree Search - DFS - Strong Connected Component - Tarjan

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Tarjan.h"

Tarjan::Tarjan(vector<EdgeVV>& Edges) : DFS(Edges),
                                        IniCycle(DFS::Vertices.size(), NOT_Visited),
                                        FinCycle(DFS::Vertices.size(), NOT_Visited) {}

void Tarjan::ProcessSCC() {
     for (VertexType Vertex = 0; Vertex < DFS::Vertices.size(); ++Vertex)
         if (this->FinCycle[Vertex] == NOT_Visited)
            SCC(Vertex);

     //Clean up aux variables
     this->QOfComponents = 0;
     this->IniCycle.assign(this->IniCycle.size(), NOT_Visited);
     this->FinCycle.assign(this->FinCycle.size(), NOT_Visited);
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
