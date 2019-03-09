/**
    File    : Kadane_run.cpp
    Author  : Menashe Rosemberg

    Dynamic Programming - Kadane

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/

#include "Kadane.h"

void Run_Dynamic_Programming_Kadane() {

    cout << "\n\t\t\t\tDynamic Programming - Kadane\n"
         << "\n\nMaximum sum expected = 6";

    vector<int32_t> Values {-2, 5, -1, 2, -3};

    cout << "\nResult: " << Kadane(Values);
}
