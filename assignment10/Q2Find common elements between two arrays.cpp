#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void findCommonElements(vector<int>& A, vector<int>& B) {
    unordered_set<int> setA(A.begin(), A.end());
    unordered_set<int> common;
    
    for (int num : B) {
        if (setA.count(num)) {
            common.insert(num);
        }
    }
    
    for (int num : common) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    findCommonElements(A, B);
    return 0;
}