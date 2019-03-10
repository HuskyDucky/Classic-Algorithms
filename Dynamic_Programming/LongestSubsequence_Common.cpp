/**
    File    : LongestSubsequence_Common.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.03            Version: 20190303.1

    Longest Common Subsequence - LCS

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "LongestSubsequence_Common.h"

string::size_type LCS(const string_view s1,const string_view s2) {
    auto s1Size = s1.size();
    auto s2Size = s2.size();
    vector<vector<uint32_t>> Quant(s1Size + 1, vector<uint32_t>(s2Size + 1, 0));

    for (uint32_t s1Pos = 0; s1Pos < s1Size; ++s1Pos)
        for (uint32_t s2Pos = 0; s2Pos < s2Size; ++s2Pos)
            Quant[s1Pos + 1][s2Pos + 1] = (s1[s1Pos] == s2[s2Pos])?
                                    Quant[s1Pos][s2Pos] + 1:
                                    max(Quant[s1Pos + 1][s2Pos], Quant[s1Pos][s2Pos + 1]);

    return Quant[s1Size][s2Size];    //Last element of Benefits has the total accumulated
}
