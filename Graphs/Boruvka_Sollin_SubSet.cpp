/**
    File    : Boruvka_Sollin_SubSet.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190311.1

    Greedy - Minimum Spanning Tree - Boruvka_Sollin SubSet

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Boruvka_Sollin_SubSet.h"

Boruvka_Sollin_SubSet::Boruvka_Sollin_SubSet(VertexType NOfVertices) : subset(NOfVertices, NOTSET) {}

VertexType Boruvka_Sollin_SubSet::InternalSearch(VertexType Vertex) const {
           if (this->subset[Vertex] == NOTSET)
              return Vertex;

        return InternalSearch(subset[Vertex]);
}

void Boruvka_Sollin_SubSet::Union(VertexType v1, VertexType v2) {
     VertexType v1_set = InternalSearch(v1);
     VertexType v2_set = InternalSearch(v2);

     this->subset[v1_set] = v2_set;
}
