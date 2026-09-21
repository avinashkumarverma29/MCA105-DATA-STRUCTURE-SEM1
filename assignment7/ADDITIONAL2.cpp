#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& arr, int k) {
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }

    vector<pair<int, int>> freqList;
    for (auto& pair : freqMap) {
        freqList.push_back(pair);
    }

    // Sort based on frequency descending; if frequencies are equal, 
    // sort based on the element value (larger element first).
    sort(freqList.begin(), freqList.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });

    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(freqList[i].first);
    }
    return result;
}

int main() {
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1};
    int k = 2;
    vector<int> ans = topKFrequent(arr, k);
    cout << "Top K Frequent: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}