/**
    File    : Knapsack.h
    Author  : Menashe Rosemberg

    Dynamic Programming - Knapsack 0/1
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
