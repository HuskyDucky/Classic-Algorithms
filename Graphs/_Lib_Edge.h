/**
    File    : _Lib_Edge.h
    Author  : Menashe Rosemberg

    Edge
**/
#ifndef EDGE_H
#define EDGE_H

#include <cinttypes>

using VertexType = uint16_t;
using WeightType = uint16_t;

struct BasicEdge {
       BasicEdge(const VertexType Vrtx1,
                 const WeightType W) : weight(W),
                                       vertex_1(Vrtx1) {}

    VertexType Vertex_1() const;
    WeightType Weight() const;

    private:
        WeightType weight;
        VertexType vertex_1;
};

struct Edge : public BasicEdge {
       Edge(const VertexType Vrtx1,
            const VertexType Vrtx2,
            const WeightType W) : BasicEdge(Vrtx1, W),
                                  vertex_2(Vrtx2) {}

    VertexType Vertex_2() const;

    private:
        VertexType vertex_2;
};

#endif // EDGE_H
