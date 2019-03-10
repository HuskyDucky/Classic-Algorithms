/**
    File    : Tarjan.h
    Author  : Menashe Rosemberg
    Created : 2019.03.09            Version: 20190309.1

    Binary Tree Search - DFS - Strong Connected Component - Tarjan

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef TARJAN_H
#define TARJAN_H

#include "DFS_Interactive.h"

using namespace std;

constexpr VertexType NOT_Visited = numeric_limits<VertexType>::max();

struct Tarjan : protected DFS {
       Tarjan(vector<EdgeVV>& Edges);

    void ProcessSCC();

    private:
        VertexType QOfComponents = 0;
        vector<VertexType> IniCycle;
        vector<VertexType> FinCycle;

        void SCC(VertexType Vertex);
};

#endif // TARJAN_H
