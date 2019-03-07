/**
    File    : DFS.cpp
    Author  : Menashe Rosemberg

    Test Breadth First Search - BFS
**/
#include "BFS.h"

BFS::BFS(vector<EdgeVV>& Edges) : Vertices(TotOfVertices(Edges)) {

    for (auto& edge : Edges)
        Vertices[edge.Vertex_1()].emplace_back(edge.Vertex_2());
}

void BFS::ProcessBFS(VertexType CurrVertex) {
     if (CurrVertex >= Vertices.size())
        throw runtime_error("BFS: Vertex doesn't exist");

     vector<uint8_t> visited(Vertices.size(), false);

     visited[CurrVertex] = true;

     for (;;) {
         auto IIt = Vertices[CurrVertex].cbegin();
         for(; IIt != Vertices[CurrVertex].cend(); ++IIt)
         if (!visited[*IIt]) {

            cout << "\nVisiting Vertex " << *IIt;
            visited[*IIt] = true;
            Pool.push(*IIt);
         }

         if (Pool.empty())
            break;
         else {
              CurrVertex = Pool.front();
              Pool.pop();
         }
     }
}
