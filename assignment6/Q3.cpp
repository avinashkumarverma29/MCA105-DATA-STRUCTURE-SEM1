#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev, *next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

int getDLLSize(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int getCLLSize(CNode* tail) {
    if (!tail) return 0;
    int count = 0;
    CNode* curr = tail->next;
    do {
        count++;
        curr = curr->next;
    } while (curr != tail->next);
    return count;
}

int main() {
    // Test sizes
    return 0;
}