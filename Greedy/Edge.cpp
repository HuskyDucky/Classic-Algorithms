/**
    File    : Edge.cpp
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Edge
**/
#include "Edge.h"

VertexType BasicEdge::Vertex_1() const {
           return this->vertex_1; }

uint16_t BasicEdge::Weight() const {
         return this->weight; }

VertexType Edge::Vertex_2() const {
           return this->vertex_2; }

