#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasPairWithSum(vector<int>& arr, int target) {
    unordered_set<int> s;
    for (int num : arr) {
        int complement = target - num;
        if (s.count(complement)) {
            return true;
        }
        s.insert(num);
    }
    return false;
}

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;
    cout << (hasPairWithSum(arr, target) ? "true" : "false") << endl;
    return 0;
}