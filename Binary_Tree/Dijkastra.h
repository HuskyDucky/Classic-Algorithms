/**
    File    : Dijkastra.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190302.1

    Greedy - Minimum Spanning Tree - Dijkastra

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
