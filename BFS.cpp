#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& adjMatrix,int s) {
    int V = adjMatrix.size();
    queue<int> q;
    vector<bool> visited(V, false);

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int v = 0; v < V; v++) {
            if(adjMatrix[curr][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

int main() {
    int V = 5;
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 4);
    
    cout << "BFS starting frpm 0;" << endl;
    bfs(adjMatrix, 0);

    return 0;
}