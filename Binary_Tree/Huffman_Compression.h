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
       Huffman(const vector<Data>& DataList);

    void ProcessHuffman();
    void PrintHuffmanTree();

    private:
        NodesPrioQueue NodeS;

        inline NodeLR Extract_D2Nodes_Lessfreq();

        void PrintHuffman(shared_ptr<Node> root, string str);
};

#endif // HUFFMAN_H
