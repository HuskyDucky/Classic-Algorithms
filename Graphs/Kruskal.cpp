/**
    File    : Kruskal.cpp
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Kruskal
**/
#include "Kruskal.h"

Kruskal::Kruskal(vector<Edge>& edges) : Edges(edges), QOfVertices(TotOfVertices(Edges)) {}

ResultType Kruskal::ProcessKruskal() {
           sort(Edges.begin(), Edges.end(), [](const Edge& e1, const Edge& e2) { return e1.Weight() < e2.Weight(); });

           Kruskal_SubSet subset(QOfVertices);

           for (uint32_t IIt = 0; IIt < Edges.size(); ++IIt)
               if (subset.isNOTACycle(Edges[IIt]))
                  VertexList.emplace_back(Edges[IIt]);

           return VertexList;
}
