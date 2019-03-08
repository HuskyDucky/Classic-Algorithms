/**
    File    : _Lib_Edge.cpp
    Author  : Menashe Rosemberg

    Edge's variation type

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "_Lib_Edge.h"

VertexType BEdgeV::Vertex() const {
           return this->vertex; }

WeightType BEdgeW::Weight() const {
           return this->weight; }

VertexType EdgeVV::Vertex_1() const { return V1.Vertex(); }
VertexType EdgeVV::Vertex_2() const { return V2.Vertex(); }



