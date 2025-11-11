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

    int key[20], parent[20];
    bool inMST[20];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, u;
        for (int v = 0; v < V; v++)
            if (!inMST[v] && key[v] < minKey)
                minKey = key[v], u = v;
        inMST[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    int cost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " = " << graph[i][parent[i]] << endl;
        cost += graph[i][parent[i]];
    }
    cout << "Total cost: " << cost;
}
