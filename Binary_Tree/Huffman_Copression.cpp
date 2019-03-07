/**
    File    : DFS.cpp
    Author  : Menashe Rosemberg

    Test Breadth First Search - BFS
**/
#include "BFS.h"

Graph_BFS::Graph_BFS(uint32_t v) : V(v), Adj(v) {}

void Graph_BFS::AddEdge(uint32_t v1, uint32_t v2) {
     Adj[v1].emplace_back(v2); }

void Graph_BFS::bfs(uint32_t v) {
     vector<uint8_t> visited(Adj.size(), false);

     cout << "\nVisiting Vertex " << v;
     visited[v] = true;

     for (;;) {
         auto IIt = Adj[v].cbegin();
         for(; IIt != Adj[v].cend(); ++IIt)
         if (!visited[*IIt]) {

            cout << "\nVisiting Vertex " << *IIt;
            visited[*IIt] = true;
            Pool.push(*IIt);
         }

         if (Pool.empty())
            break;
         else {
              v = Pool.front();
              Pool.pop();
         }
     }
}
