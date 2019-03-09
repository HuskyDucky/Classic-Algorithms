/**
    File    : Floyd.cpp
    Author  : Menashe Rosemberg

    Graph - Floyd Warshall

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef FLOYD_H
#define FLOYD_H

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;
using WeightType = uint16_t;
using WeightsMatrix = vector<vector<WeightType>>;

struct Floyd {
       Floyd(const vector<Edge>& edges);

    WeightsMatrix ProcessFloydWarshall();

    private:
        const VertexType QOfVertices;
        vector<vector<WeightType>> Weights;

};

#endif // FLOYD_H
