#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int d = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if (r == m - 1 && c == n - 1) return d;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (d + grid[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = d + grid[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
    }
    return dist[m - 1][n - 1];
}

int main() {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Minimum Total Cost: " << minPathSum(grid) << endl;
    return 0;
}