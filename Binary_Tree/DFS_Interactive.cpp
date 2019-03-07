/**
    File    : DFS.cpp
    Author  : Menashe Rosemberg

    Depth First Search - DFS Interactive
**/
#include "DFS_Interactive.h"

DFS_Interactive::DFS_Interactive(vector<EdgeVV>& Edges) : Vertices(TotOfVertices(Edges)) {

    for (auto& edge : Edges)
        Vertices[edge.Vertex_1()].emplace_back(edge.Vertex_2());
}

void DFS_Interactive::ProcessDFS(VertexType CurrVertex) {
     if (CurrVertex >= Vertices.size())
        throw runtime_error("DFS: Vertex doesn't exist");

     vector<uint8_t> visited(Vertices.size(), false);

     for (;;) {
         if (!visited[CurrVertex]) {

            cout << "\nVisiting Vertex " << CurrVertex;

            visited[CurrVertex] = true;
            Pool.push(CurrVertex);
         }

         bool found = false;

         auto IIt = Vertices[CurrVertex].cbegin();
         for (; IIt != Vertices[CurrVertex].cend(); ++IIt)
            if (!visited[*IIt]) {
                CurrVertex = *IIt;
                found = true;
                break;
            }

         if (!found) {
            Pool.pop();
            if (Pool.empty())
                break;

            CurrVertex = Pool.top();
         }
     }
}
