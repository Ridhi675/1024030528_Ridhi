#include <iostream>
using namespace std;

int adj[20][20], visited[20], V;

void DFS(int v) {
    visited[v] = 1;
    cout << v << " ";
    for (int i = 0; i < V; i++)
        if (adj[v][i] && !visited[i])
            DFS(i);
}

int main() {
    int E;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    int start;
    cin >> start;
    DFS(start);
}
