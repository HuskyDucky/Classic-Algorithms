/**
    File    : Kruskal.h
    Author  : Menashe Rosemberg
    Created : 2019.03.01            Version: 20190301.1

    Greedy - Minimum Spanning Tree - Kruskal

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <functional>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

#include "Kruskal_SubSet.h"

using namespace std;

using ResultType = vector<reference_wrapper<Edge>>;

struct Kruskal {
       Kruskal(vector<Edge>& edges);

    ResultType ProcessKruskal();

    private:
        vector<Edge>& Edges;
        const VertexType QOfVertices;

        ResultType VertexList;
};

#endif // KRUSKAL_H
