/**
    File    : Kruskal.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.01            Version: 20190301.2

    Greedy - Minimum Spanning Tree - Kruskal

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
#include "Kruskal.h"

Kruskal::Kruskal(vector<Edge>& edges) : Edges(edges), QOfVertices(TotOfVertices(Edges)) {}

ResultType Kruskal::ProcessKruskal() {
           sort(Edges.begin(), Edges.end(), [](const Edge& e1, const Edge& e2) { return e1.Weight() < e2.Weight(); });

           Kruskal_SubSet subset(QOfVertices);

           for (uint32_t CurrEdge = 0; CurrEdge < Edges.size(); ++CurrEdge)
               if (subset.isNOTACycle(Edges[CurrEdge]))
                  MST.emplace_back(Edges[CurrEdge]);

           return MST;
}
