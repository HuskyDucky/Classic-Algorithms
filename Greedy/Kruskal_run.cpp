/**
    File    : Kruskal_run.cpp
    Author  : Menashe Rosemberg

    Greedy - Minimal Spanning Tree - Kruskal
**/

#include "Kruskal.h"

#include <cstring>

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

    vector<Edge> ListOfEdges;
    //                       O  D  W
    ListOfEdges.emplace_back(0, 1, 7);
    ListOfEdges.emplace_back(0, 3, 5);
    ListOfEdges.emplace_back(1, 2, 8);
    ListOfEdges.emplace_back(1, 3, 9);
    ListOfEdges.emplace_back(1, 4, 7);
    ListOfEdges.emplace_back(2, 4, 5);
    ListOfEdges.emplace_back(3, 4, 15);
    ListOfEdges.emplace_back(3, 5, 6);
    ListOfEdges.emplace_back(4, 5, 8);
    ListOfEdges.emplace_back(4, 6, 9);
    ListOfEdges.emplace_back(5, 6, 11);

    Kruskal K(ListOfEdges);

    ResultType Results = K.ProcessKruskal();

    for (auto& IIt : Results)
        cout << IIt.get().Vertex_1() << " -> "
             << IIt.get().Vertex_2() << " Weight: "
             << IIt.get().Weight() << '\n';
}
