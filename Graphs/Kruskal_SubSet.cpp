/**
    File    : Kruskal_SubSet.cpp
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Kruskal SubSet

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/

#include "Kruskal_SubSet.h"

Kruskal_SubSet::Kruskal_SubSet (VertexType NOfVertices) {
    this->subset = new int32_t[NOfVertices];
    memset(this->subset, -1, sizeof(int32_t) * NOfVertices);
}

Kruskal_SubSet::~Kruskal_SubSet() {
    delete this->subset; }

int32_t Kruskal_SubSet::InternalSearch(VertexType i) {
        if (this->subset[i] == -1)
            return i;

        return InternalSearch(subset[i]);
}

void Kruskal_SubSet::Union(int32_t v1, int32_t v2) {
     int32_t v1_set = InternalSearch(v1);
     int32_t v2_set = InternalSearch(v2);

     this->subset[v1_set] = v2_set;
}

bool Kruskal_SubSet::isNOTACycle(const Edge& edge) {
     int32_t v1 = InternalSearch(edge.Vertex_1());
     int32_t v2 = InternalSearch(edge.Vertex_2());

     if (v1 == v2) return false;

     Union(v1, v2);

     return true;
}

