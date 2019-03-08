/**
    File    : CycleDetection.cpp
    Author  : Menashe Rosemberg

    Linked List - Cycle Detection
**/
#include "CycleDetection.h"

CycleDetect::CycleDetect(const vector<EdgeVV>& edges) : NOfVertices(TotOfVertices(edges)) {
    vector<uint8_t> V1stTime(NOfVertices, false);
    vector<uint8_t> V2ndTime(NOfVertices, false);
    vector<list<VertexType>> tmpEdges(NOfVertices);             //every line is the origin vertex

    for (auto& edge : edges)
        tmpEdges[edge.Vertex_1()].push_back(edge.Vertex_2());   //Add to Origin vertex its destiny vertex

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
