#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector<int> maxCombinations(vector<int>& a, vector<int>& b, int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int n = a.size();
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> visited;

    int i = n - 1, j = n - 1;
    maxHeap.push({a[i] + b[j], {i, j}});
    visited.insert({i, j});

    vector<int> result;
    for (int count = 0; count < k; count++) {
        auto top = maxHeap.top();
        maxHeap.pop();

        result.push_back(top.first);
        int r = top.second.first;
        int c = top.second.second;

        if (r - 1 >= 0 && visited.find({r - 1, c}) == visited.end()) {
            maxHeap.push({a[r - 1] + b[c], {r - 1, c}});
            visited.insert({r - 1, c});
        }
        if (c - 1 >= 0 && visited.find({r, c - 1}) == visited.end()) {
            maxHeap.push({a[r] + b[c - 1], {r, c - 1}});
            visited.insert({r, c - 1});
        }
    }
    return result;
}

int main() {
    vector<int> a = {1, 4, 2, 3};
    vector<int> b = {2, 5, 1, 6};
    int k = 3;
    vector<int> ans = maxCombinations(a, b, k);
    cout << "Maximum Sum Combinations: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}