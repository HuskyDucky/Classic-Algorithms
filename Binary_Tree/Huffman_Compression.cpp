/**
    File    : Huffman_Compression.cpp
    Author  : Menashe Rosemberg

    Binary Tree - Compression - Huffman

    BSD License

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
