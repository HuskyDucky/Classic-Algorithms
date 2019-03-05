/**
    File    : LongestSubsequence_Common.h
    Author  : Menashe Rosemberg

    Longest Common Subsequence - LCS
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
