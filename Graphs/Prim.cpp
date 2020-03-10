/**
    File    : Prim.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.12            Version: 20190312.1

    Greedy - Minimum Spanning Tree - Prim (Dynamic Programming)

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
#include "Prim.h"

static TheMatrix ConstructMatrix(const VertexType QofV, const vector<Edge>& edges) {
       TheMatrix WeMa(QofV, vector<WeightType>(QofV, 0));  // all Vertex has no connections '0'

       const uint32_t edgesSize = edges.size();
       for (uint32_t edge=0; edge < edgesSize ; ++edge) {
           WeMa[edges[edge].Vertex_1()][edges[edge].Vertex_2()] = edges[edge].Weight();
           WeMa[edges[edge].Vertex_2()][edges[edge].Vertex_1()] = edges[edge].Weight(); //no directional
       }

       return WeMa;
}

Prim::Prim(const vector<Edge>& edges) : QOfVertices(TotOfVertices(edges)),
                                        WeightsMatrix(ConstructMatrix(QOfVertices, edges)),
                                        VertexOri(QOfVertices, numeric_limits<VertexType>::max()),
                                        VertexNOTIncluded(QOfVertices, numeric_limits<VertexType>::max()),
                                        Included2MST(QOfVertices, false) {}

ResultType Prim::ProcessPrim() {
    VertexNOTIncluded[0] = 0;   //root
    VertexOri[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int Vertex = 1; Vertex < this->QOfVertices; ++Vertex) {
        VertexType CurrLighter = this->GetLighterLeft();
        Included2MST[CurrLighter] = true;

        for (VertexType CurrVertex = 0;
                        CurrVertex < this->QOfVertices;
                      ++CurrVertex)
            if (WeightsMatrix[CurrLighter][CurrVertex] &&
                !Included2MST[CurrVertex] &&
                WeightsMatrix[CurrLighter][CurrVertex] < VertexNOTIncluded[CurrVertex]) {
               VertexOri[CurrVertex] = CurrLighter;
               VertexNOTIncluded[CurrVertex] = WeightsMatrix[CurrLighter][CurrVertex];
            }
    }

    return this->GenerateResults();
}

inline VertexType Prim::GetLighterLeft() const {
       VertexType CurrLigher = numeric_limits<VertexType>::max();
       VertexType LighterVertex = numeric_limits<VertexType>::max();

       for (VertexType Vertex = 0; Vertex < this->QOfVertices; ++Vertex)
           if (!Included2MST[Vertex] && VertexNOTIncluded[Vertex] < CurrLigher) {
              CurrLigher = VertexNOTIncluded[Vertex];
              LighterVertex = Vertex;
       }

       return LighterVertex;
}

ResultType Prim::GenerateResults() const {
    ResultType Results;

    for (VertexType Vertex = 1; Vertex < this->QOfVertices; ++Vertex)
        Results.emplace_back(VertexOri[Vertex],
                            Vertex,
                            WeightsMatrix[Vertex][VertexOri[Vertex]]);

    return Results;
}
