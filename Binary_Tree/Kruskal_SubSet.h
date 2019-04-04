/**
    File    : Kruskal_SubSet.h
    Author  : Menashe Rosemberg
    Created : 2019.03.01            Version: 20190301.2

    Greedy - Minimum Spanning Tree - Kruskal SubSet

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef KRUSKAL_SUBSET_H
#define KRUSKAL_SUBSET_H

#include <limits>
#include <vector>

#include "Boruvka_Sollin_SubSet.h"

struct Kruskal_SubSet : private Boruvka_Sollin_SubSet {
       Kruskal_SubSet(VertexType NOfVertices);

      bool isNOTACycle(const Edge& edge);
};

#endif // KRUSKAL_SUBSET_H
