/**
    File    : Kruskal.h
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Kruskal
**/
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <set>
#include <vector>
#include <functional>

#include "Edge.h"

using namespace std;

using ResultType = vector<reference_wrapper<Edge>>;

struct Kruskal {
       Kruskal(vector<Edge>& edges);

    ResultType ProcessKruskal();

    private:
        vector<Edge>& Edges;
        uint16_t QOfVertices;

        ResultType VertexList;
};

#endif // KRUSKAL_H
