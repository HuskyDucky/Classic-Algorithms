/**
    File    : Boruvka_Sollin_SubSet.h
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190311.1

    Greedy - Minimum Spanning Tree - Boruvka_Sollin SubSet

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef BORUVKA_SOLLIN_SUBSET_H
#define BORUVKA_SOLLIN_SUBSET_H

#include <limits>
#include <vector>

#include "../_lib_/_Lib_Edge.h"

constexpr VertexType NOTSET = std::numeric_limits<VertexType>::max();

struct Boruvka_Sollin_SubSet {
       Boruvka_Sollin_SubSet(VertexType NOfVertices);

    VertexType InternalSearch(VertexType Vertex) const;
    void Union(VertexType v1, VertexType v2);

    protected:
        std::vector<VertexType> subset;
};

#endif // BORUVKA_SOLLIN_SUBSET_H
