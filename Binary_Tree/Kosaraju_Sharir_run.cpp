/**
    File    : Kosaraju_Sharir_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.10            Version: 20190310.1

    Binary Tree Search - DFS - Strong Connected Component - Kosaraju-Sharir

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include <iostream>

#include "Kosaraju_Sharir.h"

void Run_BinaryTreeSearch_DFS_Strong_Connected_Kosaraju_Sharir() {

    cout << "\n\t\t\t\tBinary Tree Search - Kosaraju_Sharir"
         << "\n\tExpected:"
         << "\n0 2 1 3"
         << "\n6 4 5"
         << "\n7"
         << "\n9 8"
         <<"\n\n\tResult:\n";

    vector<EdgeVV> Edges {  {0,1}, {0,3},
                            {1,2}, {1,4},
                            {2,0}, {2,6},
                            {3,2},
                            {4,5}, {4,6},
                            {5,6}, {5,7}, {5,8}, {5,9},
                            {6,4},
                            {7,9},
                            {8,9},
                            {9,8}
    };


    Kosaraju_Sharir T(Edges);

    T.SCC();
}
