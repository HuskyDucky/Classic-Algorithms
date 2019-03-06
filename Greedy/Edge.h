/**
    File    : Edge.h
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Edge
**/
#ifndef EDGE_H
#define EDGE_H

#include <cinttypes>

using VertexType = uint16_t;

struct BasicEdge {
       BasicEdge(const VertexType Vrtx1,
                 const uint16_t W) : weight(W),
                                     vertex_1(Vrtx1) {}

    VertexType Vertex_1() const;
    uint16_t Weight() const;

    private:
        uint16_t weight;
        VertexType vertex_1;
};

struct Edge : public BasicEdge {
       Edge(const VertexType Vrtx1,
            const VertexType Vrtx2,
            const uint16_t W) : BasicEdge(Vrtx1, W),
                                vertex_2(Vrtx2) {}

    VertexType Vertex_2() const;

    private:
        VertexType vertex_2;
};

#endif // EDGE_H
