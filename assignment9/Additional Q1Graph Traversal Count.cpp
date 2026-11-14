#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countComponents(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    vector<bool> visited(V, false);
    int components = 0;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    return components;
}

int main() {
    int V = 5, E = 3;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    
    cout << "Number of connected components: " << countComponents(V, edges) << endl;
    return 0;
}