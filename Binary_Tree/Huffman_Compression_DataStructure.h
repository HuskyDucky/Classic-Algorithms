/**
    File    : Huffman_Compression_DataStructure.h
    Author  : Menashe Rosemberg
    Created : 2019.03.06            Version: 20190306.1

    Binary Tree - Compression - Huffman

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef HUFFMAN_DATASTRUCT_H
#define HUFFMAN_DATASTRUCT_H

#include <memory>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Data {
       Data(char tdata, unsigned tfreq) : m_data(tdata), m_freq(tfreq) {}

       char data() const { return m_data; }
       unsigned freq() const { return m_freq; }

    private:
        char m_data;
        unsigned m_freq;
};

struct Node;
struct NodeLR {
       NodeLR(shared_ptr<Node> L = nullptr,
              shared_ptr<Node> R = nullptr) : left(L), right(R) {}
    shared_ptr<Node> left;
    shared_ptr<Node> right;
};

struct Node : Data, NodeLR {
       Node(char data, unsigned freq) : Data(data, freq) {}};

namespace std {
    template<> struct less<shared_ptr<Node>> {
        bool operator()(const shared_ptr<Node> l, const shared_ptr<Node> r) {
             return (l->freq() > r->freq()); } }; }

using NodesPrioQueue = priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>>;

using CodeTableHash =  map<char, string>;   //string is the Huffman code

#endif // HUFFMAN_DATASTRUCT_H
