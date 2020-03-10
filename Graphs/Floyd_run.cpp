/**
    File    : Floyd_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.07            Version: 20190307.1

    Graph - Cycle Detection - Floyd Warshall

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

    Based on source code from: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16
**/
#include <iostream>
#include <iomanip>

#include "../_lib_/_Lib_Edge.h"
#include "Floyd.h"

#include <vector>

using namespace std;

void Run_Graph_Floyd() {
    /*
             10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
             3
    */

    cout << "\n\t\t\t\tGraph - Cycle Detection - Floyd\n"
         << "\n\nResult expected:"
         << "\n   0  1  2  3"
         << "\n   ----------"
         << "\n 0|0  5  8  9"
         << "\n 1|   0  3  4"
         << "\n 2|      0  1"
         << "\n 3|         0"
         << "\n\nResult:";

                              // O  D  W
    vector<Edge> ListOfEdges {  {0, 1, 5},
                                {1, 2, 3},
                                {2, 3, 1},
                                {0, 3, 10}
    };

    Floyd F(ListOfEdges);
    WeightsMatrix WeM = F.ProcessFloydWarshall();

    for (auto& Lin : WeM) {
        cout << "\n\t";
        for (auto& Weight : Lin)
            if (Weight == numeric_limits<WeightType>::max())
                cout << "    ";
            else
                cout << setw(2) << Weight << "  ";
    }

}
