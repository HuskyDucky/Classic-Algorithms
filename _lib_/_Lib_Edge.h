/**
    File    : _Lib_Edge.h
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190307.2

    Edge's variation type

    BSD License

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
