/**
    File    : Kadane_run.cpp
    Author  : Menashe Rosemberg

    Dynamic Programming - Kadane
**/

#include "Kadane.h"

void Run_Dynamic_Programming_Kadane() {

    cout << "\n\t\t\t\tDynamic Programming - Kadane\n"
         << "\n\nMaximum sum expected = 6";

    vector<int32_t> Values {-2, 5, -1, 2, -3};

    cout << "\nResult: " << Kadane(Values);
}
