/**
    File    : Brent.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.05            Version: 20190305.1

    Linked List - Cycle Detection - Brent

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef BRENT_H
#define BRENT_H

#include <utility>

using namespace std;

struct Node {
       Node(int Data) : data(Data) {}

    int data;
    Node* next;
};

using NodePair = pair<Node*, Node*>;

NodePair detectCycle(Node* head);

#endif // BRENT_H
