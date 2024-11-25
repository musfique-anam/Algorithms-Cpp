#include <iostream>
using namespace std;    

class DFS {
    static const int V = 4;
    int adjMatrix[V][V];
    bool visited[V];

public:
    DFS() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0;
            }
            visited[i] = false;
        }
    }
    
    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1;
    }

    void DFSMain(int vertex) {
        visited[vertex] = true;
        cout << (char)(vertex + 'A') << " ";

        for (int i =0; i < V; i++) {
            if (adjMatrix[vertex][i] &&!visited[i]) {
                DFSMain(i);
            }
        }
    }
};

int main() {
    DFS g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Following is Depth First Traversal starting from vertex C: " << endl;
    g.DFSMain(2);

    return 0;
}