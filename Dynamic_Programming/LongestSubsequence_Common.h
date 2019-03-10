/**
    File    : LongestSubsequence_Common.h
    Author  : Menashe Rosemberg
    Created : 2019.03.03            Version: 20190303.1

    Longest Common Subsequence - LCS

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef LCS_H
#define LCS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string_view>

using namespace std;

string::size_type LCS(const string_view s1, const string_view s2);

#endif // LCS_H
