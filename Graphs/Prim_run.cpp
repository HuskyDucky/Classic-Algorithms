/**
    File    : Prim_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.12            Version: 20190312.2

    Greedy - Minimum Spanning Tree - Prim (Dynamic Programming)

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
