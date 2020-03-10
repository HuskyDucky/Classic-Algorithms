/**
    File    : Brent.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.05            Version: 20190305.1

    Linked List - Cycle Detection - Brent

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
