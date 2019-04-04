/**
    File    : Boruvka_Sollin.h
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190311.1

    Greedy - Minimum Spanning Tree - Boruvka_Sollin

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef BORUVKA_SOLLIN_H
#define BORUVKA_SOLLIN_H

#include <vector>
#include <functional>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

#include "Boruvka_Sollin_SubSet.h"

using namespace std;

using ResultType = vector<reference_wrapper<Edge>>;

struct Boruvka_Sollin {
       Boruvka_Sollin(vector<Edge>& edges);

    ResultType ProcessBoruvka_Sollin();

    private:
        vector<Edge>& Edges;
        const VertexType QOfVertices;
        Boruvka_Sollin_SubSet Subset;
        vector<VertexType> Cheapest;

        ResultType MST;

        inline void UpdateCheapest();
        inline void AddCurrCheapest2MST();
};

#endif // BORUVKA_SOLLIN_H
