/**
    File    : CycleDetection_run.cpp
    Author  : Menashe Rosemberg

    Linked List - Cycle Detection

**/
#include <iostream>

#include "CycleDetection.h"

void Run_Cycle_Detection_in_Linked_List() {

    cout << "\n\t\t\t\tCycle Detection in a Linked List\n"
         << "\n\nResult expected:"
         << "\n\tCycle detected"
         << "\n\nResult:\n\t";

    vector<EdgeVV> Edges {{0, 1},
                          {0, 2},
                          {1, 2},
                          {2, 0},   //make a cycle
                          {2, 3},
                          {3, 3}    //make a cycle
    };

    CycleDetect C(Edges);

    if (!C.isCyclic())
        cout << "NO ";

    cout << "Cycle Detected";


}
