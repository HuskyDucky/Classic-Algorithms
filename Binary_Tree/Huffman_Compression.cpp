/**
    File    : Huffman_Compression.cpp
    Author  : Menashe Rosemberg

    Binary Tree - Compression - Huffman
**/
#include "Huffman_Compression.h"



Huffman::Huffman(const vector<Data>& DataList)  {
    for (uint32_t IIt = 0; IIt < DataList.size(); ++IIt)                           //Create notes to all elements
        NodeS.push(new Node(DataList[IIt].data(), DataList[IIt].freq()));
}

inline NodeLR Huffman::Extract_D2Nodes_Lessfreq() {
       NodeLR NLR;

       NLR.left = NodeS.top();
       NodeS.pop();

       NLR.right = NodeS.top();
       NodeS.pop();

       return NLR;
}

void Huffman::ProcessHuffman() {
     while (NodeS.size() != 1) {
            NodeLR LessFreqNodes = Extract_D2Nodes_Lessfreq();

            //create a subroots signed with '$' whereas its freq is the sum of the less freq nodes and pointing to these less freq nodes
            Node* SubRoot(new Node('$', LessFreqNodes.left->freq() + LessFreqNodes.right->freq()));
            SubRoot->left = LessFreqNodes.left;
            SubRoot->right= LessFreqNodes.right;

            NodeS.push(SubRoot);
     }
}

void Huffman::PrintHuffmanTree() {
     PrintHuffman(NodeS.top(), "");
}

void Huffman::PrintHuffman(Node* root, string str) {
     if (root) {
        if (root->data() != '$')
            cout << root->data() << ": " << str << "\n";

        this->PrintHuffman(root->left, str + "0");
        this->PrintHuffman(root->right, str + "1");
     }
}
