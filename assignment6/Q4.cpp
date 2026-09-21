#include <iostream>
using namespace std;

struct DNode {
    char data;
    DNode* prev, *next;
    DNode(char val) : data(val), prev(nullptr), next(nullptr) {}
};

bool isPalindrome(DNode* head, DNode* tail) {
    if (!head) return true;
    while (head != tail && tail->next != head) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    // Example: L <-> E <-> V <-> E <-> L
    DNode* head = new DNode('L');
    head->next = new DNode('E'); head->next->prev = head;
    head->next->next = new DNode('V'); head->next->next->prev = head->next;
    head->next->next->next = new DNode('E'); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DNode('L'); head->next->next->next->next->prev = head->next->next->next;
    DNode* tail = head->next->next->next->next;

    cout << (isPalindrome(head, tail) ? "True" : "False") << endl;
    return 0;
}