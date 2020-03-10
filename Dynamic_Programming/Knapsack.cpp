/**
    File    : Knapsack.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.07            Version: 20190307.1

    Dynamic Programming - Knapsack 0/1

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
