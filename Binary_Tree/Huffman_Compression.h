/**
    File    : Huffman_Compression.h
    Author  : Menashe Rosemberg

    Binary Tree - Compression - Huffman
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
