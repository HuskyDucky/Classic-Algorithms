/**
    File    : Kruskal.h
    Author  : Menashe Rosemberg

    Greedy - Minimal Spanning Tree - Kruskal
**/
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>

#include <set>
#include <vector>
#include <functional>

using namespace std;
using VertexType = uint16_t;

struct Edge {
       Edge(const VertexType Vrtx1,
            const VertexType Vrtx2,
            const uint16_t W) : vertex_1(Vrtx1),
                                vertex_2(Vrtx2),
                                weight(W) {}

        VertexType Vertex_1() const;
        VertexType Vertex_2() const;
        uint16_t Weight() const;

    private:
        VertexType vertex_1;
        VertexType vertex_2;
        uint16_t weight;
};

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
