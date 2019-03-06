/**
    File    : _Lib_QuantVertices.h
    Author  : Menashe Rosemberg

   Return the quantity of vertices from a vector of edges
**/
#ifndef QVERTICES_H
#define QVERTICES_H

#include <set>
#include <vector>

#include "_Lib_Edge.h"

using namespace std;

VertexType TotOfVertices(const vector<Edge>& edges);

#endif // QVERTICES_H
