/**
    File    : Knapsack_run.cpp
    Author  : Menashe Rosemberg

    Dynamic Programming - Knapsack 0/1
**/

#include "Knapsack.h"

void Run_Knapsack_0_1() {

    cout << "\n\t\t\t\tKnapsack\n"
         << "\n\nMaximum Benefits expected 26";

    uint16_t maxWeight = 20;
                             //  W, B
    vector<Element> Elements {  {2, 3},
                                {4, 5},
                                {5, 8},
                                {3, 4},
                                {9, 10}};

    cout << "\nResult: " << Knapsack(maxWeight, Elements);
    cin.get();
}
