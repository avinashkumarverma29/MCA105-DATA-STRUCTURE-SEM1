#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int, int>>> adj(N + 1);
    for (auto& time : times) {
        adj[time[0]].push_back({time[1], time[2]});
    }

    vector<int> dist(N + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int max_time = 0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == 1e9) return -1;
        max_time = max(max_time, dist[i]);
    }
    return max_time;
}

int main() {
    int N = 4, K = 2;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << "Network Delay Time: " << networkDelayTime(times, N, K) << endl;
    return 0;
}