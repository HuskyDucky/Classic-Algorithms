/**
    File    : _Lib_QuantVertices.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.03            Version: 20190303.2

    Return the quantity of vertices from a vector of edges

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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

