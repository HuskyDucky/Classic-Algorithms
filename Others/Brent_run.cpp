/**
    File    : Brent_run.cpp
    Author  : Menashe Rosemberg

    Linked List - Cycle Detection - Brent

    Based on source code from:https://www.geeksforgeeks.org/brents-cycle-detection-algorithm

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include <iostream>
#include <iomanip>

#include "Brent.h"

using namespace std;

void Run_Cycle_Detection_in_Linked_List_Brent() {

    cout << "\n\t\t\t\tCycle Detection in a Linked List Brent\n"
         << "\n\nResult expected:"
         << "\nCycle detected starting at Node 8 and back to Node 3"
         << "\n\nResult:\n";

    Node* head = new Node(1);
    Node* res = head;
    for (int RandValue = 2; RandValue < 9; ++RandValue) {    //Create a new node always connected to current last node in the list
        res->next = new Node(RandValue);
        res = res->next;
    }

    head->next->next->next->next->next->next->next->next = head->next->next;  // Create a loop for testing. Last Node cycled with the third

    NodePair nodepair = detectCycle(head);

    if (nodepair.first == nullptr)
        cout << "No loop";
    else
        cout << "Cycle detected starting at Node " << nodepair.second->data << " and back to Node " << nodepair.first->data;

    for (int X = 1; X < 9; ++X) {   //clear up all Nodes (8)
        res = head->next;
        delete head;
        head = res;
    }

}
