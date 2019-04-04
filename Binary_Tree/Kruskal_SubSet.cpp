/**
    File    : Kruskal_SubSet.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.01            Version: 20190301.2

    Greedy - Minimum Spanning Tree - Kruskal SubSet

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Kruskal_SubSet.h"

Kruskal_SubSet::Kruskal_SubSet(VertexType NOfVertices) : Boruvka_Sollin_SubSet(NOfVertices) {}

bool Kruskal_SubSet::isNOTACycle(const Edge& edge) {
     VertexType v1 = InternalSearch(edge.Vertex_1());
     VertexType v2 = InternalSearch(edge.Vertex_2());

     if (v1 == v2) return false;

     Union(v1, v2);

     return true;
}
