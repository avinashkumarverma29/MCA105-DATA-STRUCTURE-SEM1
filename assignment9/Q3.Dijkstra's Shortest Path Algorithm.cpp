#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(int V, int src, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex Distance from Source " << src << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "Node " << i << " -> " << dist[i] << "\n";
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    // {destination, weight}
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    dijkstra(V, 0, adj);
    return 0;
}