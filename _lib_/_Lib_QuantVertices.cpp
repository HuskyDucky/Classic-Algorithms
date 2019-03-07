/**
    File    : _Lib_QuantVertices.cpp
    Author  : Menashe Rosemberg

   Return the quantity of vertices from a vector of edges
**/
#include <set>
#include <vector>

#include "_Lib_Edge.h"

using namespace std;

template <typename EDGE>
VertexType TotOfVertices(const vector<EDGE>& edges) {
    try {
        set<VertexType> VertexList;

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

