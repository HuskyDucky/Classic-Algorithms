/**
    File    : Knapsack.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.07            Version: 20190307.1

    Dynamic Programming - Knapsack 0/1

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Knapsack.h"

uint16_t Knapsack(uint16_t maxWeight,const ElementList& element) {
         const uint16_t NOfElem = element.size();
         vector<vector<uint16_t>> Benefits(NOfElem + 1, vector<uint16_t>(maxWeight + 1, 0));

        for (uint16_t Lin = 0; Lin < NOfElem; ++Lin)
            for (uint16_t ValidW = 1; ValidW <= maxWeight; ++ValidW)
                Benefits[Lin + 1][ValidW] = (element[Lin].Weight <= ValidW &&
                                             element[Lin].Benefit + Benefits[Lin][ValidW - element[Lin].Weight] > Benefits[Lin][ValidW])?
                                             element[Lin].Benefit + Benefits[Lin][ValidW - element[Lin].Weight]: //add new benefit
                                             Benefits[Lin][ValidW];                                              //Keep the current status of benefits

        return Benefits[NOfElem][maxWeight];    //Last element of Benefits has the total accumulated
}
