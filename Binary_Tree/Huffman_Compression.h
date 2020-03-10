/**
    File    : Huffman_Compression.h
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
**/
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>

#include "Huffman_Compression_DataStructure.h"

using namespace std;

struct Huffman {
       Huffman(const string& toEncode);

    void ProcessHuffman();
    string Decode() const;

    void PrintHashTable() const;
    string Code() const;

    private:
        string Text;

        NodesPrioQueue NodeS;
        CodeTableHash HashList;

        string HashCode;

        inline void Hashkeeper(shared_ptr<Node> root, string str);
        inline NodeLR Extract_D2Nodes_Lessfreq();
        inline void SaveHashCode();

};

#endif // HUFFMAN_H
