/**
    File    : Kadane.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.06            Version: 20190306.1

    Dynamic Programming - Kadane

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Kadane.h"

int32_t Kadane(vector<int32_t>& Values) {
        int32_t  Max_Atual = 0;
        int32_t  Max_Total = numeric_limits<int32_t>::min();
        uint32_t size_Values = Values.size();

        if (size_Values == 0) return 0;

        for (uint32_t IIt = 0; IIt < size_Values; IIt++) {
            Max_Atual = Max_Atual + Values[IIt];

            if(Max_Atual < 0)
                Max_Atual = 0;
            if(Max_Atual > Max_Total)
                Max_Total = Max_Atual;
        }

	return Max_Total;
}
