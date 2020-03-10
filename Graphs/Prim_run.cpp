/**
    File    : Prim_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.12            Version: 20190312.2

    Greedy - Minimum Spanning Tree - Prim (Dynamic Programming)

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
#include <iostream>

#include "../_lib_/_Lib_Edge.h"
#include "Prim.h"

void Run_Greedy_Prim() {

    cout << "\n\t\t\t\tGreedy - Minimal Spanning Tree - Prim\n"
         << "\n\nResult expected:"
         << "\nC -> B Weight 7"
         << "\nA -> C Weight 6"
         << "\nB -> D Weight 1"
         << "\nF -> E Weight 2"
         << "\nD -> F Weight 3"
         << "\nK -> G Weight 10"
         << "\nG -> H Weight 15"
         << "\nG -> I Weight 5"
         << "\nE -> J Weight 18"
         << "\nL -> K Weight 12"
         << "\nJ -> L Weight 4"
         << "\n\nTotal Weight: 83"
         << "\n\nResult:\n";

    enum Vx : VertexType {A, B, C, D, E, F, G, H, I, J, K, L};

    vector<Edge> ListOfEdges {{A, B, 13},
                              {A, C, 6},
                              {B, C, 7},
                              {B, D, 1},
                              {C, D, 14},
                              {C, E, 8},
                              {D, E, 9},
                              {D, F, 3},
                              {C, H, 20},
                              {E, F, 2},
                              {E, J, 18},
                              {H, G, 15},
                              {H, J, 17},
                              {G, I, 5},
                              {G, J, 19},
                              {G, K, 10},
                              {K, J, 16},
                              {I, K, 11},
                              {K, L, 12},
                              {L, J, 4}
    };

    Prim Pm(ListOfEdges);

    ResultType Results = Pm.ProcessPrim();

    WeightType Total_Weight = 0;
    for (auto& IIt : Results) {
        cout << static_cast<char>(65+IIt.Vertex_1()) << " -> "
             << static_cast<char>(65+IIt.Vertex_2()) << " Weight: "
             << IIt.Weight() << '\n';
        Total_Weight += IIt.Weight();
    }
    cout << "\nTotal Weight: " << Total_Weight << '\n';
}
