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
#ifndef DIJCASTRA_H
#define DIJCASTRA_H

#include <list>
#include <queue>
#include <vector>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;

using Distance_Vertice  = pair<WeightType, VertexType>;

struct Dijkastra {
       Dijkastra(const vector<Edge>& edges);

    WeightType ProcessDijcastra(const VertexType Vertice_Ori, const VertexType Vertice_Des);

    private:
        vector<list<EdgeWV>> Edges;
        vector<uint8_t> notVisited;
        vector<WeightType> Distancies;
        priority_queue<Distance_Vertice,
                       vector<Distance_Vertice>,
                       greater<Distance_Vertice>
                      > PriorityQueue;

};

#endif // DIJCASTRA_H
