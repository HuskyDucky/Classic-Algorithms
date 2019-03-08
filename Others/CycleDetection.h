/**
    File    : CycleDetection.cpp
    Author  : Menashe Rosemberg

    Linked List - Cycle Detection
**/
#ifndef CYCLE_DETECTION_H
#define CYCLE_DETECTION_H

#include <list>
#include <vector>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

using namespace std;

struct CycleDetect {
       CycleDetect(const vector<EdgeVV>& edges);

    bool isCyclic();

    private:
        VertexType NOfVertices;
        vector<list<VertexType>> EdgeS;
        vector<uint8_t> Visited1stTime;
        vector<uint8_t> Visited2ndTime;

        bool isCyclicUtil(VertexType Vertex);
};

#endif // CYCLE_DETECTION_H
