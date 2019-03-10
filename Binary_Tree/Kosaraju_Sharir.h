/**
    File    : Kosaraju_Sharir.h
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190310.1

    Binary Tree Search - DFS - Strong Connected Component - Kosaraju-Sharir

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef KOSARAJU_SHARIR_H
#define KOSARAJU_SHARIR_H

#include <algorithm>

#include "DFS_Interactive.h"

using namespace std;

struct DFS_KS : public DFS {
       DFS_KS(vector<EdgeVV> Edges) : DFS(Edges) {}};

struct Kosaraju_Sharir : protected DFS_KS {
       Kosaraju_Sharir(vector<EdgeVV>& Edges);
       Kosaraju_Sharir(vector<list<VertexType>>& DVertices); //Insert the vertices direct to DFS and invert the graph
                                                             //the internal stack(Pool) and Visited is never used by recursive calls
    void SCC();

    private:
        void ProcessSCC(VertexType CurrVertex, vector<uint8_t>& visited);
        void FillPool_DFS_Ordered(VertexType CurrVertex, vector<uint8_t>& visited, stack<VertexType>& pool);
};

#endif // KOSARAJU_SHARIR_H
