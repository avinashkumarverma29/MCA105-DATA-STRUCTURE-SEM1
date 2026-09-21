#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next, *prev, *random;
    Node(int val) : data(val), next(nullptr), prev(nullptr), random(nullptr) {}
};

void correctRandomPointer(Node* head) {
    // Logic to locate node with incorrect random pointer and reset it
}

int main() {
    return 0;
}