/**
    File    : Dijkastra.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190302.1

    Greedy - Minimum Spanning Tree - Dijkastra

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
#include "Dijkastra.h"

Dijkastra::Dijkastra(const vector<Edge>& edges) {

    VertexType QOfVertices(TotOfVertices(edges));

    for (VertexType IIt = 0; IIt < QOfVertices; ++IIt) {
        this->Edges.emplace_back();                                 //Every line is the Origin Vertex (Vertex_1)
        this->Distancies.push_back(numeric_limits<WeightType>::max());
        this->notVisited.push_back(true);
    }

    for (auto& edge : edges)
        Edges[edge.Vertex_1()].emplace_back(edge.Vertex_2(), edge.Weight());
}

WeightType Dijkastra::ProcessDijcastra(const VertexType Vertice_Ori, const VertexType Vertice_Des) {
           Distancies[Vertice_Ori] = 0;                                   //Distance to/from original point is zero;
           PriorityQueue.emplace(Distancies[Vertice_Ori], Vertice_Ori);   //Distance to/from original point is zero;

           while (!PriorityQueue.empty()) {
                 VertexType Vertice = this->PriorityQueue.top().second;
                 this->PriorityQueue.pop();

                 if (this->notVisited[Vertice]) {
                    this->notVisited[Vertice] = false;

                    for (auto& IIt : this->Edges[Vertice])
                        if (this->Distancies[IIt.Vertex()] > this->Distancies[Vertice] + IIt.Weight()) {
                            this->Distancies[IIt.Vertex()] = this->Distancies[Vertice] + IIt.Weight();
                            this->PriorityQueue.emplace(this->Distancies[IIt.Vertex()], IIt.Vertex());
                        }
                 }
           }

           return Distancies[Vertice_Des];
}
