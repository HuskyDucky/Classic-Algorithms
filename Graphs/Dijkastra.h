/**
    File    : Dijkastra.cpp
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Dijkastra
**/
#ifndef DIJCASTRA_H
#define DIJCASTRA_H

#include <list>
#include <queue>
#include <vector>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;

using Distance_Vertice  = pair<WeightType, VertexType>;

struct Dijkastra {
       Dijkastra(const vector<Edge>& edges);

    WeightType ProcessDijcastra(const VertexType Vertice_Ori, const VertexType Vertice_Des);

    private:
        vector<list<EdgeWV>> Edges;
        vector<uint8_t> notVisited;
        vector<WeightType> Distancies;
        priority_queue<Distance_Vertice,
                       vector<Distance_Vertice>,
                       greater<Distance_Vertice>
                      > PriorityQueue;

};

#endif // DIJCASTRA_H
