#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        // Adjacency Matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        // Adjacency List
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printAdjMatrix();
    g.printAdjList();

    return 0;
}
