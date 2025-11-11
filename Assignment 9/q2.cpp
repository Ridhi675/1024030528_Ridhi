#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int v) { V = v; adj.resize(v); }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v : adj[u])
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
        }
    }
};

int main() {
    int V, E, u, v, s;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; i++) { cin >> u >> v; g.addEdge(u, v); }
    cin >> s;
    g.BFS(s);
}
