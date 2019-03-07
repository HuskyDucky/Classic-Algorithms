/**
    File    : _Lib_Edge.cpp
    Author  : Menashe Rosemberg

    Edge
**/
#include "_Lib_Edge.h"

VertexType BEdgeV::Vertex() const {
           return this->vertex; }

WeightType BEdgeW::Weight() const {
           return this->weight; }

VertexType EdgeVV::Vertex_1() const { return V1.Vertex(); }
VertexType EdgeVV::Vertex_2() const { return V2.Vertex(); }



