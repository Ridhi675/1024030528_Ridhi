#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    bool directed;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int v, bool dir = false) {
        vertices = v;
        directed = dir;
        adjMatrix.resize(v, vector<int>(v, 0));
        adjList.resize(v);
    }

    // Add Edge
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjList[u].push_back(v);

        if (!directed) {
            adjMatrix[v][u] = 1;
            adjList[v].push_back(u);
        }
    }

    // Display Adjacency Matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    // Display Adjacency List
    void displayList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int j : adjList[i])
                cout << j << " ";
            cout << endl;
        }
    }

    // Find Degree of Vertex (for undirected graph)
    void degree(int v) {
        cout << "Degree of vertex " << v << " = " << adjList[v].size() << endl;
    }

    // In-degree (for directed graph)
    void inDegree(int v) {
        int count = 0;
        for (int i = 0; i < vertices; i++)
            if (adjMatrix[i][v] == 1)
                count++;
        cout << "In-degree of vertex " << v << " = " << count << endl;
    }

    // Out-degree (for directed graph)
    void outDegree(int v) {
        cout << "Out-degree of vertex " << v << " = " << adjList[v].size() << endl;
    }

    // Adjacent vertices of a vertex
    void adjacentVertices(int v) {
        cout << "Adjacent vertices of " << v << ": ";
        for (int i : adjList[v])
            cout << i << " ";
        cout << endl;
    }

    // Count number of edges
    void countEdges() {
        int count = 0;
        for (int i = 0; i < vertices; i++)
            for (int j : adjList[i])
                count++;

        if (!directed)
            count /= 2;

        cout << "Number of edges = " << count << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    int V, choice, u, v;
    bool dir;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> dir;

    Graph g(V, dir);

    cout << "Enter edges (u v), enter -1 -1 to stop:\n";
    while (true) {
        cin >> u >> v;
        if (u == -1 || v == -1)
            break;
        g.addEdge(u, v);
    }

    g.displayMatrix();
    g.displayList();

    cout << "\n--- Operations ---\n";
    cout << "1. Degree of vertex\n2. In-degree of vertex\n3. Out-degree of vertex\n4. Adjacent vertices\n5. Count edges\n6. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 6) break;

        switch (choice) {
            case 1:
                cout << "Enter vertex: ";
                cin >> v;
                g.degree(v);
                break;
            case 2:
                cout << "Enter vertex: ";
                cin >> v;
                g.inDegree(v);
                break;
            case 3:
                cout << "Enter vertex: ";
                cin >> v;
                g.outDegree(v);
                break;
            case 4:
                cout << "Enter vertex: ";
                cin >> v;
                g.adjacentVertices(v);
                break;
            case 5:
                g.countEdges();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
