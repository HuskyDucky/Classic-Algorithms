/**
    File    : Dijkastra.cpp
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Dijkastra
**/
#ifndef DIJCASTRA_H
#define DIJCASTRA_H

#include <set>
#include <list>
#include <queue>
#include <vector>

#include "Edge.h"

using namespace std;

using Distance_Vertice  = pair<uint16_t, uint16_t>;

struct Dijkastra {
       Dijkastra(const vector<Edge>& edges);

    uint16_t ProcessDijcastra(const uint16_t Vertice_Ori, const uint16_t Vertice_Des);

    private:
        vector<list<BasicEdge>> Edges;
        vector<uint8_t> notVisited;
        vector<uint16_t> Distancies;
        priority_queue<Distance_Vertice,
                       vector<Distance_Vertice>,
                       greater<Distance_Vertice>
                      > PriorityQueue;

};

#endif // DIJCASTRA_H
