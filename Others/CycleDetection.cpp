/**
    File    : CycleDetection.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.04            Version: 20190304.1

    Linked List - Cycle Detection

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
#include "CycleDetection.h"

CycleDetect::CycleDetect(const vector<EdgeVV>& edges) : NOfVertices(TotOfVertices(edges)) {
    vector<uint8_t> V1stTime(NOfVertices, false);
    vector<uint8_t> V2ndTime(NOfVertices, false);
    vector<list<VertexType>> tmpEdges(NOfVertices);             //every line is the origin vertex

    for (auto& edge : edges)
        tmpEdges[edge.Vertex_1()].push_back(edge.Vertex_2());   //Add to Origin vertex its destiny

    Visited1stTime.swap(V1stTime);
    Visited2ndTime.swap(V2ndTime);
    EdgeS.swap(tmpEdges);
}

bool CycleDetect::isCyclicUtil(VertexType Vertex) {
     if (Visited1stTime[Vertex] == false) {
        Visited1stTime[Vertex] = true;          //check the element as visited
        Visited2ndTime[Vertex] = true;          //Controller for recursion check

        for (auto edge = EdgeS[Vertex].cbegin(); edge != EdgeS[Vertex].cend(); ++edge)
            if ((!Visited1stTime[*edge] &&
                isCyclicUtil(*edge))    ||
                Visited2ndTime[*edge])
                return true;
    }

    Visited2ndTime[Vertex] = false; //Ok, It is not find a cycle

    return false;
}

bool CycleDetect::isCyclic() {
     for (VertexType Vertex = 0; Vertex < NOfVertices; ++Vertex)
         if (isCyclicUtil(Vertex))
            return true;

    return false;
}
