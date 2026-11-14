#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// --- Kruskal's Algorithm ---
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j])
                parent[root_i] = root_j;
            else if (rank[root_i] > rank[root_j])
                parent[root_j] = root_i;
            else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    int mst_weight = 0;
    cout << "Kruskal's MST Edges:\n";
    for (auto& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.unite(edge.u, edge.v);
            mst_weight += edge.weight;
            cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
        }
    }
    cout << "Total Weight (Kruskal): " << mst_weight << "\n\n";
}

// --- Prim's Algorithm ---
void primMST(int V, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> inMST(V, false);
    int mst_weight = 0;

    pq.push({0, 0}); // {weight, vertex}

    cout << "Prim's MST Edges:\n";
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int u = p.second;
        int weight = p.first;

        if (inMST[u]) continue;
        inMST[u] = true;
        mst_weight += weight;

        if (weight > 0) {
            cout << "Node " << u << " added with weight " << weight << "\n";
        }

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int wt = neighbor.second;
            if (!inMST[v]) {
                pq.push({wt, v});
            }
        }
    }
    cout << "Total Weight (Prim): " << mst_weight << "\n";
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    kruskalMST(V, edges);

    vector<vector<pair<int, int>>> adj(V);
    for (auto& e : edges) {
        adj[e.u].push_back({e.v, e.weight});
        adj[e.v].push_back({e.u, e.weight});
    }
    primMST(V, adj);

    return 0;
}