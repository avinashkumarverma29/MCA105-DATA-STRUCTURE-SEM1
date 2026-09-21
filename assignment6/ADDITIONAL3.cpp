#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev, *next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

DNode* reverseKGroupDLL(DNode* head, int k) {
    if (!head) return nullptr;
    DNode* current = head;
    DNode* next = nullptr;
    DNode* newHead = nullptr;
    int count = 0;

    while (current != nullptr && count < k) {
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        newHead = current;
        current = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseKGroupDLL(next, k);
        if (head->next) head->next->prev = head;
    }

    return newHead;
}

int main() {
    // Test reverseKGroupDLL
    return 0;
}