#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int mostFrequent(vector<int>& arr) {
    unordered_map<int, int> freqMap;
    int maxFreq = 0;
    int result = arr[0];
    
    for (int num : arr) {
        freqMap[num]++;
        if (freqMap[num] > maxFreq) {
            maxFreq = freqMap[num];
            result = num;
        } else if (freqMap[num] == maxFreq) {
            result = max(result, num);
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 4, 1};
    cout << mostFrequent(arr) << endl; // Output: 2
    return 0;
}