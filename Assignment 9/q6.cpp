#include <iostream>
#include <climits>
using namespace std;

int main() {
    int V;
    cin >> V;
    int graph[20][20];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    int src;
    cin >> src;

    int dist[20], visited[20];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, minDist = INT_MAX;
        for (int i = 0; i < V; i++)
            if (!visited[i] && dist[i] < minDist)
                minDist = dist[i], u = i;
        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = 0; i < V; i++)
        cout << src << " -> " << i << " = " << dist[i] << endl;
}
