/**
    File    : Kruskal_run.cpp
    Author  : Menashe Rosemberg

    Greedy - Minimum Spanning Tree - Kruskal
**/
#include <iostream>

#include "_Lib_Edge.h"
#include "Kruskal.h"

void Run_Greedy_Kruskal() {

    cout << "\n\t\t\t\tGreedy - Minimal Spanning Tree - Kruskal\n"
         << "\n\nResult expected:"
         << "\n0 -> 3 WeightL 5"
         << "\n2 -> 4 WeightL 5"
         << "\n3 -> 5 WeightL 6"
         << "\n0 -> 1 WeightL 7"
         << "\n1 -> 4 WeightL 7"
         << "\n4 -> 6 WeightL 9"
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

    Kruskal K(ListOfEdges);

    ResultType Results = K.ProcessKruskal();

    for (auto& IIt : Results)
        cout << IIt.get().Vertex_1() << " -> "
             << IIt.get().Vertex_2() << " Weight: "
             << IIt.get().Weight() << '\n';
}
