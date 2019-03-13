/**
    File    : Main.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190310.2

    Construct a simple question and wait the answer

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/

#include <vector>
#include "_lib_/Ask_Menu.h"

void Run_Cycle_Detection_in_Linked_List();
void Run_Cycle_Detection_in_Linked_List_Brent();
void Run_BinaryTree_Compression_Huffman();
void Run_BinaryTreeSearch_BFS();
void Run_BinaryTreeSearch_DFS();
void Run_BinaryTreeSearch_DFS_Strong_Connected_Kosaraju_Sharir();
void Run_BinaryTreeSearch_DFS_Strong_Connected_Tarjan();
void Run_Greedy_Boruvka_Sollin();
void Run_Greedy_Kruskal();
void Run_Greedy_Prim();
void Run_Greedy_Dijkastra();
void Run_Graph_Floyd();
void Run_Dynamic_Programming_Kadane();
void Run_Dynamic_Programming_Knapsack_0_1();
void Run_Dynamic_Programming_LCS();
void Run_Dynamic_Programming_LPS();

int main() {

    ListOfOptQuest Options
                    {{"Linked List - Cycle_Detection",                               [](){ Run_Cycle_Detection_in_Linked_List();                        }},
                    {"Linked List - Cycle_Detection - Brent",                        [](){ Run_Cycle_Detection_in_Linked_List_Brent();                  }},
                    {"Binary Tree - Compression - Huffman",                          [](){ Run_BinaryTree_Compression_Huffman();                        }},
                    {"Binary Tree Search - BFS",                                     [](){ Run_BinaryTreeSearch_BFS();                                  }},
                    {"Binary Tree Search - DFS Interactive",                         [](){ Run_BinaryTreeSearch_DFS();                                  }},
                    {"Binary Tree Search - DFS - Strong Connected - Kosaraju-Sharir",[](){ Run_BinaryTreeSearch_DFS_Strong_Connected_Kosaraju_Sharir(); }},
                    {"Binary Tree Search - DFS - Strong Connected - Tarjan",         [](){ Run_BinaryTreeSearch_DFS_Strong_Connected_Tarjan();          }},
                    {"Graph - Minimum Spanning Tree - Floyd Warshall",               [](){ Run_Graph_Floyd();                                           }},
                    {"Graph - Greedy - Minimum Spanning Tree - Boruvka-Sollin",      [](){ Run_Greedy_Boruvka_Sollin();                                 }},
                    {"Graph - Greedy - Minimum Spanning Tree - Kruskal",             [](){ Run_Greedy_Kruskal();                                        }},
                    {"Graph - Greedy - Minimum Spanning Tree - Prim",                [](){ Run_Greedy_Prim();                                           }},
                    {"Graph - Greedy - Minimum Spanning Tree - Dijkastra",           [](){ Run_Greedy_Dijkastra();                                      }},
                    {"Dynamic Programming- Kadane",                                  [](){ Run_Dynamic_Programming_Kadane();                            }},
                    {"Dynamic Programming- Knapsack 0 1",                            [](){ Run_Dynamic_Programming_Knapsack_0_1();                      }},
                    {"Dynamic Programming- Longest Common Subsequence",              [](){ Run_Dynamic_Programming_LCS();                               }},
                    {"Dynamic Programming- Longest Palindromic Subsequence",         [](){ Run_Dynamic_Programming_LPS();                               }}
    } ;

    Ask_Menu TheQuestion("\n\nChoose the Algorithm you are learning:\n", move(Options));
    TheQuestion.Show();

    return 0;
}
