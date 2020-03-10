/**
    File    : Kosaraju_Sharir.h
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190310.1

    Binary Tree Search - DFS - Strong Connected Component - Kosaraju-Sharir

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
