/**
    File    : _Lib_QuantVertices.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.03            Version: 20190303.2

    Return the quantity of vertices from a vector of edges

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
#include <set>
#include <vector>

#include "_Lib_Edge.h"

using namespace std;

template <typename EDGE>
VertexType TotOfVertices(const vector<EDGE>& edges) {
    try {
        set<VertexType> VertexList;                     //the edges elements are the vertices itself as well

        for (auto& edge : edges) {
            VertexList.emplace(edge.Vertex_1());
            VertexList.emplace(edge.Vertex_2());
        }

        VertexType QOfVertices = 0;

        for (auto checkSequence : VertexList)
            if (QOfVertices == checkSequence)
                ++QOfVertices;
            else
                throw;

        return QOfVertices;

    } catch(...) {
        throw runtime_error("\n\n\nVertex are not continuous...\n\n\n");
    }
}

