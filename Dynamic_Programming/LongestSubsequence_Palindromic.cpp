/**
    File    : LongestSubsequence_Palindromic.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.03            Version: 20190303.1

    Longest Palindromic Subsequence - LPS

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
