#include <iostream>
#include <vector>

using namespace std;

void improvedSelectionSort(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while (low < high) {
        int minIdx = low, maxIdx = low;
        for (int i = low; i <= high; i++) {
            if (arr[i] < arr[minIdx]) minIdx = i;
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }

        swap(arr[low], arr[minIdx]);
        
        // If the maximum element was at the 'low' index, 
        // its position has now shifted to 'minIdx'
        if (maxIdx == low) {
            maxIdx = minIdx;
        }

        swap(arr[high], arr[maxIdx]);

        low++;
        high--;
    }
}

int main() {
    vector<int> arr = {29, 72, 98, 13, 87, 66, 52, 51, 36};
    improvedSelectionSort(arr);
    cout << "Sorted array using Improved Selection Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}