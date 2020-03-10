/**
    File    : Boruvka_Sollin.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190311.1

    Greedy - Minimum Spanning Tree - Boruvka_Sollin

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
#include "Boruvka_Sollin.h"

Boruvka_Sollin::Boruvka_Sollin(vector<Edge>& edges) : Edges(edges),
                                                      QOfVertices(TotOfVertices(Edges)),
                                                      Subset(QOfVertices),
                                                      Cheapest(QOfVertices, NOTSET) {}

ResultType Boruvka_Sollin::ProcessBoruvka_Sollin() {
           for (VertexType Trees = this->QOfVertices; Trees > 1; --Trees) {       //Guarantee that all Vertices will be connected
               fill(Cheapest.begin(), Cheapest.end(), NOTSET) ;                   //Reset to next cycle;
               this->UpdateCheapest();
               this->AddCurrCheapest2MST();
            }

    return MST;
}

inline void Boruvka_Sollin::UpdateCheapest() {
       for (uint32_t CurrEdge = 0; CurrEdge < Edges.size(); ++CurrEdge) {
           VertexType set1 = Subset.InternalSearch(Edges[CurrEdge].Vertex_1());
           VertexType set2 = Subset.InternalSearch(Edges[CurrEdge].Vertex_2());

           if (set1 == set2) continue;                                          //Guarantee the found Vertices are not in the same component

           if (Cheapest[set1] == NOTSET ||                                      //Choose the cheapest edge to CurrEdge
               Edges[Cheapest[set1]].Weight() > Edges[CurrEdge].Weight())
              Cheapest[set1] = CurrEdge;

           if (Cheapest[set2] == NOTSET ||
               Edges[Cheapest[set2]].Weight() > Edges[CurrEdge].Weight())
              Cheapest[set2] = CurrEdge;
       }
}

inline void Boruvka_Sollin::AddCurrCheapest2MST() {
       for (VertexType Vertex=0; Vertex < this->QOfVertices; ++Vertex)
           if (Cheapest[Vertex] != NOTSET) {
              VertexType set1 = Subset.InternalSearch(Edges[Cheapest[Vertex]].Vertex_1());
              VertexType set2 = Subset.InternalSearch(Edges[Cheapest[Vertex]].Vertex_2());

              if (set1 == set2) continue;

              MST.emplace_back(Edges[Cheapest[Vertex]]);

              Subset.Union(set1, set2);
           }
}
