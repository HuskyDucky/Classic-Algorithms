/**
    File    : Huffman_Compression.h
    Author  : Menashe Rosemberg
    Created : 2019.03.06            Version: 20190306.1

    Binary Tree - Compression - Huffman

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
