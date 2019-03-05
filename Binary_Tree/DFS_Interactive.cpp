/**
    File    : DFS.cpp
    Author  : Menashe Rosemberg

    Depth First Search - DFS Interactive
**/
#include "DFS_Interactive.h"

Graph_DFS_Interactive::Graph_DFS_Interactive(uint32_t v) : V(v), Adj(v) {}

void Graph_DFS_Interactive::AddEdge(uint32_t v1, uint32_t v2) {
     Adj[v1].emplace_back(v2); }

void Graph_DFS_Interactive::dfs(uint32_t v) {
     vector<uint8_t> visited(Adj.size(), false);

     for (;;) {
         if (!visited[v]) {

            cout << "\nVisiting Vertex " << v;

            visited[v] = true;
            S.push(v);
         }

         bool found = false;

         auto IIt = Adj[v].cbegin();
         for (; IIt != Adj[v].cend(); ++IIt)
            if (!visited[*IIt]) {
                v = *IIt;
                found = true;
                break;
            }

         if (!found) {
            S.pop();
            if (S.empty())
                break;

            v = S.top();
         }
     }
}
