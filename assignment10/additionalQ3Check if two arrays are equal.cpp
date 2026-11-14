#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool areArraysEqual(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) return false;
    
    unordered_map<int, int> countMap;
    for (int num : a) {
        countMap[num]++;
    }
    
    for (int num : b) {
        if (countMap.find(num) == countMap.end() || countMap[num] == 0) {
            return false;
        }
        countMap[num]--;
    }
    return true;
}

int main() {
    vector<int> a = {1, 2, 5, 4, 0};
    vector<int> b = {2, 4, 5, 0, 1};
    cout << (areArraysEqual(a, b) ? "true" : "false") << endl;
    return 0;
}