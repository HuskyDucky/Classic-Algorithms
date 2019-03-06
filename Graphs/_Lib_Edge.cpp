/**
    File    : _Lib_Edge.cpp
    Author  : Menashe Rosemberg

    Edge
**/
#include "_Lib_Edge.h"

VertexType BasicEdge::Vertex_1() const {
           return this->vertex_1; }

WeightType BasicEdge::Weight() const {
           return this->weight; }

VertexType Edge::Vertex_2() const {
           return this->vertex_2; }

