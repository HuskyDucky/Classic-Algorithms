/**
    File    : Knapsack.h
    Author  : Menashe Rosemberg
    Created : 2019.03.07            Version: 20190307.1

    Dynamic Programming - Knapsack 0/1

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <vector>

using namespace std;

struct Element {
       Element(uint16_t W, uint16_t B) : Weight(W), Benefit(B) {}
       uint16_t Weight;
       uint16_t Benefit;
};

using ElementList = vector<Element>;

uint16_t Knapsack(uint16_t maxWeight,const ElementList& element);

#endif // KNAPSACK_H
