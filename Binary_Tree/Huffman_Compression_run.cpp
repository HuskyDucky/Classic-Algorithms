/**
    File    : Huffman_Compression_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.06            Version: 20190306.1

    Binary Tree - Compression - Huffman

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

    Based on code from https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3 (Aditya Goel's code)
**/
#include <iostream>
#include "Huffman_Compression.h"

using namespace std;

void Run_BinaryTree_Compression_Huffman() {

    cout << "\n\t\t\t\tBinary Tree - Compression - Huffman"
         << "\n\nExpected:"
         << "\nM: 100"
         << "\na: 110"
         << "\ne: 01"
         << "\nh: 111"
         << "\nn: 00"
         << "\ns: 101"
         << "\n\tCode: 100010011010111101"
         << "\n\tDecode: Menashe"
         << "\n\nResult:\n";

    string Test("Menashe");

    Huffman H(Test);

    H.ProcessHuffman();

    H.PrintHashTable();

    cout << "\tCode: " << H.Code();
    cout << "\n\tDecode: " << H.Decode();
}
