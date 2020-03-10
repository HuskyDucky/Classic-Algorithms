/**
    File    : Boruvka_Sollin.h
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190311.1

    Greedy - Minimum Spanning Tree - Boruvka_Sollin

    BSD License

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/
#ifndef BORUVKA_SOLLIN_H
#define BORUVKA_SOLLIN_H

#include <vector>
#include <functional>

#include "../_lib_/_Lib_Edge.h"
#include "../_lib_/_Lib_QuantVertices.cpp"

#include "Boruvka_Sollin_SubSet.h"

using namespace std;

using ResultType = vector<reference_wrapper<Edge>>;

struct Boruvka_Sollin {
       Boruvka_Sollin(vector<Edge>& edges);

    ResultType ProcessBoruvka_Sollin();

    private:
        vector<Edge>& Edges;
        const VertexType QOfVertices;
        Boruvka_Sollin_SubSet Subset;
        vector<VertexType> Cheapest;

        ResultType MST;

        inline void UpdateCheapest();
        inline void AddCurrCheapest2MST();
};

#endif // BORUVKA_SOLLIN_H
