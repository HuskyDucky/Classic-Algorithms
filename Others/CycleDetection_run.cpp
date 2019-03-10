/**
    File    : CycleDetection_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.04            Version: 20190304.1

    Linked List - Cycle Detection

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
