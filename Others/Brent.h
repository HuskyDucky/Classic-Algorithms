/**
    File    : Brent.cpp
    Author  : Menashe Rosemberg

    Linked List - Cycle Detection - Brent
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
