#include <iostream>
using namespace std;

// Function to calculate parity (number of set bits)
int getParity(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

// Struct definitions and removal logic for DLL and CLL can be structured here.
int main() {
    cout << "Parity of 11 (binary 1011) is: " << getParity(11) << endl; // Output: 3 (odd)
    return 0;
}