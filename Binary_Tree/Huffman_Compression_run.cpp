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

    cout << "\n\tCode: " << H.Code();
    cout << "\n\tDecode: " << H.Decode();
}
