/**
    File    : Knapsack_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.07            Version: 20190307.1

    Dynamic Programming - Knapsack 0/1

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/

#include "Knapsack.h"

void Run_Dynamic_Programming_Knapsack_0_1() {

    cout << "\n\t\t\t\tDynamic Programming - Knapsack\n"
         << "\n\nMaximum Benefits expected 26";

    uint16_t maxWeight = 20;
                             //  W, B
    vector<Element> Elements {  {2, 3},
                                {4, 5},
                                {5, 8},
                                {3, 4},
                                {9, 10}};

    cout << "\nResult: " << Knapsack(maxWeight, Elements);
}
