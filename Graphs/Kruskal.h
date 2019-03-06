/**
    File    : Kruskal.h
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Kruskal
**/
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <functional>

#include "_Lib_Edge.h"
#include "_Lib_QuantVertices.h"

#include "Kruskal_SubSet.h"

using namespace std;

using ResultType = vector<reference_wrapper<Edge>>;

struct Kruskal {
       Kruskal(vector<Edge>& edges);

    ResultType ProcessKruskal();

    private:
        vector<Edge>& Edges;
        const VertexType QOfVertices;

        ResultType VertexList;
};

#endif // KRUSKAL_H
