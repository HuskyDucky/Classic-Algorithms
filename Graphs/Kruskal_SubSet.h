/**
    File    : Kruskal_SubSet.h
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Kruskal SubSet
**/
#ifndef KRUSKAL_SUBSET_H
#define KRUSKAL_SUBSET_H

#include "Kruskal.h"

#include <cstring>

struct Kruskal_SubSet {
       Kruskal_SubSet(VertexType NOfVertices);
      ~Kruskal_SubSet();

      bool isNOTACycle(const Edge& edge);

    private:
        int32_t* subset;

        int32_t InternalSearch(VertexType i);
        void Union(int32_t v1, int32_t v2);
};

#endif // KRUSKAL_SUBSET_H
