/**
    File    : Main.cpp
    Author  : Menashe Rosemberg
**/

#include <vector>
#include "Ask.h"

void Run_BinaryTreeSearch_DFS_Interactive();
void Run_BinaryTreeSearch_BFS();
void Run_Dynamic_Programming_Kadane();
void Run_Dynamic_Programming_Knapsack_0_1();
void Run_Dynamic_Programming_LCS();
void Run_Dynamic_Programming_LPS();
void Run_Greedy_Kruskal();

int main() {

    std::vector<std::string> Options {
                                "Binary Tree Search - DFS Interactive",
                                "Binary Tree Search - BFS",
                                "Dynamic Programming- Kadane",
                                "Dynamic Programming- Knapsack 0 1",
                                "Dynamic Programming- LCS",
                                "Dynamic Programming- LPS",
                                "Greedy             - Kruskal",
                                "Exit"
    };

    Ask TheQuestion;
    TheQuestion << "\n\nChoose your Algorithm:\n";
    TheQuestion.hastheAnswers(move(Options));
    TheQuestion.hastheBehavior(ASK::ANSWARE_BY_LETTERS);

    for(;;) {
        char Answer = TheQuestion.wasmade();

        switch (Answer) {
            case 'a': Run_BinaryTreeSearch_DFS_Interactive(); continue;
            case 'b': Run_BinaryTreeSearch_BFS();             continue;
            case 'c': Run_Dynamic_Programming_Kadane();       continue;
            case 'd': Run_Dynamic_Programming_Knapsack_0_1(); continue;
            case 'e': Run_Dynamic_Programming_LCS();          continue;
            case 'f': Run_Dynamic_Programming_LPS();          continue;
            case 'g': Run_Greedy_Kruskal();                   continue;
        }
        break;
    }

    return 0;
}