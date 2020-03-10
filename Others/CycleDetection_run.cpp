/**
    File    : CycleDetection_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.04            Version: 20190304.1

    Linked List - Cycle Detection

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
