/**
    File    : Dijkastra.cpp
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Dijkastra
**/
#include "Dijkastra.h"

Dijkastra::Dijkastra(const vector<Edge>& edges) {

    VertexType QOfVertices(TotOfVertices(edges));

    for (VertexType IIt = 0; IIt < QOfVertices; ++IIt) {
        this->Edges.emplace_back();                                 //Every line is the Origin Vertex (Vertex_1)
        this->Distancies.push_back(numeric_limits<WeightType>::max());
        this->notVisited.push_back(true);
    }

    for (auto& edge : edges)
        Edges[edge.Vertex_1()].emplace_back(edge.Vertex_2(), edge.Weight());
}

WeightType Dijkastra::ProcessDijcastra(const VertexType Vertice_Ori, const VertexType Vertice_Des) {
           Distancies[Vertice_Ori] = 0;                                   //Distance to/from original point is zero;
           PriorityQueue.emplace(Distancies[Vertice_Ori], Vertice_Ori);   //Distance to/from original point is zero;

           while (!PriorityQueue.empty()) {
                 VertexType Vertice = this->PriorityQueue.top().second;
                 this->PriorityQueue.pop();

                 if (this->notVisited[Vertice]) {
                    this->notVisited[Vertice] = false;

                    for (auto& IIt : this->Edges[Vertice])
                        if (this->Distancies[IIt.Vertex_1()] > this->Distancies[Vertice] + IIt.Weight()) {
                            this->Distancies[IIt.Vertex_1()] = this->Distancies[Vertice] + IIt.Weight();
                            this->PriorityQueue.emplace(this->Distancies[IIt.Vertex_1()], IIt.Vertex_1());
                        }
                 }
           }

           return Distancies[Vertice_Des];
}
