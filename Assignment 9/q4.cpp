#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[20];

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int V, E;
    cin >> V >> E;
    Edge edges[50];
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    for (int i = 0; i < V; i++) parent[i] = i;

    for (int i = 0; i < E - 1; i++)
        for (int j = 0; j < E - i - 1; j++)
            if (edges[j].w > edges[j + 1].w)
                swap(edges[j], edges[j + 1]);

    int cost = 0;
    for (int i = 0; i < E; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (find(u) != find(v)) {
            cout << u << " - " << v << " = " << edges[i].w << endl;
            cost += edges[i].w;
            union_set(u, v);
        }
    }
    cout << "Total cost: " << cost;
}
