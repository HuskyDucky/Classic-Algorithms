/**
    File    : Huffman_Compression_DataStructure.h
    Author  : Menashe Rosemberg

    Binary Tree - Compression - Huffman
**/
#ifndef HUFFMAN_DATASTRUCT_H
#define HUFFMAN_DATASTRUCT_H

#include <vector>
#include <queue>

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
       NodeLR(Node* L = nullptr,
              Node* R = nullptr) : left(L), right(R) {}
    Node* left;
    Node* right;
};

struct Node : Data, NodeLR {
       Node(char data, unsigned freq) : Data(data, freq) {}};

namespace std {
    template<> struct less<Node*> {
        bool operator()(const Node* l, const Node* r) {
             return (l->freq() > r->freq()); } }; }

using NodesPrioQueue = std::priority_queue<Node*, std::vector<Node*>>;

#endif // HUFFMAN_DATASTRUCT_H
