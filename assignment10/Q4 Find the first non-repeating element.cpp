#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstNonRepeating(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }
    
    for (int num : nums) {
        if (freqMap[num] == 1) {
            return num;
        }
    }
    return -1; // If no non-repeating element exists
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    cout << firstNonRepeating(nums) << endl;
    return 0;
}