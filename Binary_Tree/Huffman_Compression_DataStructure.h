/**
    File    : Huffman_Compression_DataStructure.h
    Author  : Menashe Rosemberg

    Binary Tree - Compression - Huffman
**/
#ifndef HUFFMAN_DATASTRUCT_H
#define HUFFMAN_DATASTRUCT_H

#include <memory>
#include <vector>
#include <queue>

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

#endif // HUFFMAN_DATASTRUCT_H
