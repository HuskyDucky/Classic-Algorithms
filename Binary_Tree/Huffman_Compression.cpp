/**
    File    : Huffman_Compression.cpp
    Author  : Menashe Rosemberg

    Binary Tree - Compression - Huffman
**/
#include "Huffman_Compression.h"

Huffman::Huffman(const string& toEncode) : Text(toEncode) {
    map<char, uint32_t> LetterFreq;

         string::size_type sSize  = this->Text.size();
    for (string::size_type letter = 0; letter < sSize; ++letter)
        ++LetterFreq[this->Text[letter]];

    //convert to nodes
    for (auto& LeFr : LetterFreq)
        NodeS.emplace(new Node(LeFr.first, LeFr.second));
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
            shared_ptr<Node> SubRoot(new Node('$', LessFreqNodes.left->freq() + LessFreqNodes.right->freq()));
            SubRoot->left = LessFreqNodes.left;
            SubRoot->right= LessFreqNodes.right;

            this->NodeS.push(SubRoot);
     }

     this->Hashkeeper(NodeS.top(), "");

     this->SaveHashCode();
}

inline void Huffman::Hashkeeper(shared_ptr<Node> root, string str) {
       if (root) {
          if (root->data() != '$')
             this->HashList[root->data()] = str;

          this->Hashkeeper(root->left, str + "0");
          this->Hashkeeper(root->right, str + "1");
       }
}

inline void Huffman::SaveHashCode() {
       for (auto i : this->Text)
           this->HashCode += this->HashList.find(i)->second;
}

string Huffman::Code() const {
       return this->HashCode;
}

string Huffman::Decode() const {
       string dcode("");

       shared_ptr<Node> cNode = this->NodeS.top();

            string::size_type sSize  = this->HashCode.size();
       for (string::size_type letter = 0; letter < sSize; ++letter) {

            cNode = this->HashCode[letter] == '0'?
                                        cNode->left:
                                        cNode->right;

            if (cNode->left  == nullptr &&
                cNode->right == nullptr) {      //leaf found
                dcode += cNode->data();
                cNode = this->NodeS.top();
            }
       }

    return dcode;
}

void Huffman::PrintHashTable() const {
     for (auto& IIt : HashList)
         cout << IIt.first << ": " << IIt.second << "\n";
}
