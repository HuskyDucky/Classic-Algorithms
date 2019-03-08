/**
    File    : _Lib_Edge.h
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190307.2

    Edge's variation type

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef EDGE_H
#define EDGE_H

#include <cinttypes>

using VertexType = uint16_t;
using WeightType = uint16_t;

struct BEdgeV {
       BEdgeV(const VertexType Vrtx) : vertex(Vrtx) {}

    VertexType Vertex() const;

    private:
        VertexType vertex;
};

struct BEdgeW {
       BEdgeW(const WeightType W) : weight(W) {}

    WeightType Weight() const;

    private:
        WeightType weight;
};

struct EdgeVV {
       EdgeVV(const VertexType Vrtx1,
              const VertexType Vrtx2) : V1(Vrtx1), V2(Vrtx2) {}

    VertexType Vertex_1() const;
    VertexType Vertex_2() const;

    private:
        BEdgeV V1;
        BEdgeV V2;
};

struct EdgeWV : public BEdgeW, BEdgeV {
       EdgeWV(const VertexType Vrtx,
              const WeightType W) : BEdgeW(W), BEdgeV(Vrtx) {}};

struct Edge : public BEdgeW, EdgeVV {
       Edge(const VertexType Vrtx1,
            const VertexType Vrtx2,
            const WeightType W) : BEdgeW(W), EdgeVV(Vrtx1, Vrtx2) {}};

#endif // EDGE_H
