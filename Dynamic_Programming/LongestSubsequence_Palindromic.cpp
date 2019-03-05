/**
    File    : LongestSubsequence_Palindromic.cpp
    Author  : Menashe Rosemberg

    Longest Palindromic Subsequence - LPS
**/
#include "LongestSubsequence_Palindromic.h"

string::size_type LPS(const string_view s) {
    auto sSize = s.size();
    vector<vector<uint32_t>> Quant(sSize, vector<uint32_t>(sSize, 0));    //string with 1 character is a palindrome with size 1

    for (string::size_type LR = 0; LR < sSize; ++LR)
        Quant[LR][LR] = 1;

    for (string::size_type DSize = 2; DSize <= sSize; ++DSize)
        for (string::size_type Lef = 0, Rig = DSize - 1 + Lef; Rig < sSize; ++Lef, Rig++)
            Quant[Lef][Rig] = s[Lef] == s[Rig]?
                                        Quant[Lef + 1][Rig - 1] + 2:
                                        max(Quant[Lef][Rig - 1], Quant[Lef + 1][Rig]);

    return Quant[0][sSize - 1];
}
