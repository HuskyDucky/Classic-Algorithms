/**
    File    : Floyd.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.07            Version: 20190307.1

    Graph - Floyd Warshall

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
