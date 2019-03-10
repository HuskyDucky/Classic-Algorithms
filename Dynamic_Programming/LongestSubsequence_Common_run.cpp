/**
    File    : LongestSubsequence_Common_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.03            Version: 20190303.1

    Longest Common Subsequence - LCS

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/

#include "LongestSubsequence_Common.h"

void Run_Dynamic_Programming_LCS() {

    cout << "\n\t\t\t\tDynamic Programming - Longest Common Subsequence - LCS\n"
         << "\n\nMaximum Length expected 3";

    cout << "\nLength: " << LCS("ABCB", "BDCAB");
}
