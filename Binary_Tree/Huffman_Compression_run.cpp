/**
    File    : Huffman_Compression_run.cpp
    Author  : Menashe Rosemberg

    Binary Tree - Compression - Huffman

    Based on code from https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3 (Aditya Goel's code)
**/
#include <iostream>
#include "Huffman_Compression.h"

using namespace std;

void Run_BinaryTree_Compression_Huffman() {

    cout << "\n\t\t\t\tBinary Tree - Compression - Huffman"
         << "\n\nExpected:\n"
         << "\nf: 0"
         << "\nc: 100"
         << "\nd: 101"
         << "\na: 1100"
         << "\nb: 1101"
         << "\ne: 111"
"\n\nResult:\n";

    vector<Data> DataList { {'a', 5 },
                            {'b', 9 },
                            {'c', 12},
                            {'d', 13},
                            {'e', 16},
                            {'f', 45}
    };

    Huffman H(DataList);

    H.ProcessHuffman();

    H.PrintHuffmanTree();
}
