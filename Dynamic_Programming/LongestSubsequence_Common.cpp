/**
    File    : LongestSubsequence_Common.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.03            Version: 20190303.1

    Longest Common Subsequence - LCS

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
