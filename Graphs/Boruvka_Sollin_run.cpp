/**
    File    : Boruvka_Sollin_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190311.1

    Greedy - Minimum Spanning Tree - Boruvka_Sollin

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include <iostream>

#include "../_lib_/_Lib_Edge.h"
#include "Boruvka_Sollin.h"

void Run_Greedy_Boruvka_Sollin() {

    cout << "\n\t\t\t\tGreedy - Minimal Spanning Tree - Boruvka_Sollin\n"
         << "\n0 -> 3 Weight 5"
         << "\n0 -> 1 Weight 7"
         << "\n2 -> 4 Weight 5"
         << "\n3 -> 5 Weight 6"
         << "\n4 -> 6 Weight 9"
         << "\n1 -> 4 Weight 7"
         << "\n\nTotal Weight: 39"
         << "\n\nResult:\n";

                            // V1 V2 W
    vector<Edge> ListOfEdges {{0, 1, 7},
                              {0, 3, 5},
                              {1, 2, 8},
                              {1, 3, 9},
                              {1, 4, 7},
                              {2, 4, 5},
                              {3, 4, 15},
                              {3, 5, 6},
                              {4, 5, 8},
                              {4, 6, 9},
                              {5, 6, 11}
    };

    Boruvka_Sollin BS(ListOfEdges);

    ResultType Results = BS.ProcessBoruvka_Sollin();

    WeightType Total_Weight = 0;
    for (auto& IIt : Results) {
        cout << IIt.get().Vertex_1() << " -> "
             << IIt.get().Vertex_2() << " Weight: "
             << IIt.get().Weight() << '\n';
        Total_Weight += IIt.get().Weight();
    }
    cout << "\nTotal Weight: " << Total_Weight << '\n';
}
