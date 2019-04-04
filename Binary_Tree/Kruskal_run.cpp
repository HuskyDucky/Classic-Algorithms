/**
    File    : Kruskal_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.01            Version: 20190301.2

    Greedy - Minimum Spanning Tree - Kruskal

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include <iostream>

#include "../_lib_/_Lib_Edge.h"
#include "Kruskal.h"

void Run_Greedy_Kruskal() {

    cout << "\n\t\t\t\tGreedy - Minimal Spanning Tree - Kruskal\n"
         << "\n\nResult expected:"
         << "\nB -> D Weight 1"
         << "\nE -> F Weight 2"
         << "\nD -> F Weight 3"
         << "\nL -> J Weight 4"
         << "\nG -> I Weight 5"
         << "\nA -> C Weight 6"
         << "\nB -> C Weight 7"
         << "\nG -> K Weight 10"
         << "\nK -> L Weight 12"
         << "\nH -> G Weight 15"
         << "\nE -> J Weight 18"
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

    Kruskal Kl(ListOfEdges);

    ResultType Results = Kl.ProcessKruskal();

    WeightType Total_Weight = 0;
    for (auto& IIt : Results) {
        cout << static_cast<char>(65+IIt.get().Vertex_1()) << " -> "
             << static_cast<char>(65+IIt.get().Vertex_2()) << " Weight: "
             << IIt.get().Weight() << '\n';
        Total_Weight += IIt.get().Weight();
    }
    cout << "\nTotal Weight: " << Total_Weight << '\n';
}
