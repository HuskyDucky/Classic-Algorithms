/**
    File    : Brent_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.05            Version: 20190305.1

    Linked List - Cycle Detection - Brent

    Based on source code from:https://www.geeksforgeeks.org/brents-cycle-detection-algorithm

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
