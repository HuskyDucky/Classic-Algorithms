/**
    File    : Floyd.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.07            Version: 20190307.1

    Graph - Floyd Warshall

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Floyd.h"

Floyd::Floyd(const vector<Edge>& edges) : QOfVertices(TotOfVertices(edges)) {
    vector<vector<WeightType>> Weits(QOfVertices, vector<WeightType>(QOfVertices, numeric_limits<WeightType>::max()));
    Weights.swap(Weits);

    for (auto& CurrEdge : edges)
        Weights[CurrEdge.Vertex_1()][CurrEdge.Vertex_2()] = CurrEdge.Weight();
}

WeightsMatrix Floyd::ProcessFloydWarshall() {
    for (uint16_t IIt_1 = 0; IIt_1 < QOfVertices; IIt_1++)           // Pick all vertices as source one by one
        for (uint16_t IIt_2 = 0; IIt_2 < QOfVertices; ++IIt_2)       // Pick all vertices as destination for the above picked source
            for (uint16_t IIt_3 = 0; IIt_3 < QOfVertices; IIt_3++)
                if (Weights[IIt_2][IIt_3] > Weights[IIt_2][IIt_1] + Weights[IIt_1][IIt_3])   //vertex IIt_1 is on the shortest path from  IIt_2 to IIt_3 then
                    Weights[IIt_2][IIt_3] = Weights[IIt_2][IIt_1] + Weights[IIt_1][IIt_3];   //update the value of dist[IIt_2][IIt_3]

    return Weights;
}