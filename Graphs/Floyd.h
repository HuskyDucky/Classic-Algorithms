/**
    File    : Floyd.cpp
    Author  : Menashe Rosemberg

    Graph - Floyd Warshall
**/
#ifndef FLOYD_H
#define FLOYD_H

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;
using WeightType = uint16_t;
using WeightsMatrix = vector<vector<WeightType>>;

struct Floyd {
       Floyd(const vector<Edge>& edges);

    WeightsMatrix ProcessFloydWarshall();

    private:
        const VertexType QOfVertices;
        vector<vector<WeightType>> Weights;

};

#endif // FLOYD_H
