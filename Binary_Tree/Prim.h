/**
    File    : Prim.h
    Author  : Menashe Rosemberg
    Created : 2019.03.12            Version: 20190312.1

    Greedy - Minimum Spanning Tree - Prim (Dynamic Programming)

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef PRIM_H
#define PRIM_H

#include <vector>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;

using TheMatrix = vector<vector<WeightType>>;
using ResultType = vector<Edge>;

struct Prim {
       Prim(const vector<Edge>& edges);
    ResultType ProcessPrim();

    private:
       const VertexType QOfVertices;
       const TheMatrix WeightsMatrix;

       vector<VertexType> VertexOri;
       vector<VertexType> VertexNOTIncluded;
       vector<uint8_t> Included2MST;

       inline VertexType GetLighterLeft() const;
       ResultType GenerateResults() const;

        ResultType MST;
};

#endif // Prim_H
