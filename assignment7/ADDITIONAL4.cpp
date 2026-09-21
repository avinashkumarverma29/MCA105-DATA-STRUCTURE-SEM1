#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortEvenOddPlaces(vector<int>& arr) {
    vector<int> evenPlaced, oddPlaced;
    for (size_t i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) evenPlaced.push_back(arr[i]);
        else oddPlaced.push_back(arr[i]);
    }

    sort(evenPlaced.begin(), evenPlaced.end());
    sort(oddPlaced.begin(), oddPlaced.end(), greater<int>());

    size_t eIdx = 0, oIdx = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) arr[i] = evenPlaced[eIdx++];
        else arr[i] = oddPlaced[oIdx++];
    }
}

int main() {
    vector<int> arr = {3, 1, 2, 4, 5, 9, 13, 14, 12};
    sortEvenOddPlaces(arr);
    cout << "Modified array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}