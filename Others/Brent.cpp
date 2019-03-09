/**
    File    : Brent.cpp
    Author  : Menashe Rosemberg

    Linked List - Cycle Detection - Brent

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Brent.h"

NodePair detectCycle(Node* head) {
         if (head == nullptr) return NodePair();

         Node* first_pointer = head;
         Node* second_pointer = head->next;

         int CheckPoint = 1;
         int NOfLoops = 1;

         while (second_pointer != first_pointer) {   //it is a cycle
               if (second_pointer == nullptr)        //it is not a loop
                   return NodePair();

               if (NOfLoops == CheckPoint) {
                   CheckPoint *= 2;
                   NOfLoops = 0;

                   first_pointer = second_pointer;
               }

               second_pointer = second_pointer->next;
               ++NOfLoops;
         }

    second_pointer = head;
    while (NOfLoops > 0) {                      //from the start find the Node where the cycle start
        second_pointer = second_pointer->next;
        --NOfLoops;
    }

    first_pointer = head;                       //move both pointer to find the beginning of cycle
    while (second_pointer != first_pointer) {
        second_pointer = second_pointer->next;
        first_pointer = first_pointer->next;
    }

    second_pointer = first_pointer->next;       //find the Node that made the cycle
    while (second_pointer->next != first_pointer)
          second_pointer = second_pointer->next;

    return NodePair(first_pointer, second_pointer);
}
