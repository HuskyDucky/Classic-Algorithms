/**
    File    : LongestSubsequence_Common_run.cpp
    Author  : Menashe Rosemberg

    Longest Common Subsequence - LCS
**/

#include "LongestSubsequence_Common.h"

void Run_Dynamic_Programming_LCS() {

    cout << "\n\t\t\t\tDynamic Programming - Longest Common Subsequence - LCS\n"
         << "\n\nMaximum Length expected 3";

    cout << "\nLength: " << LCS("ABCB", "BDCAB");
}
