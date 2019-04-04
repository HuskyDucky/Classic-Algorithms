/**
    File    : Boruvka_Sollin.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190311.1

    Greedy - Minimum Spanning Tree - Boruvka_Sollin

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
