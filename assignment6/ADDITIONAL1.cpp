#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (!head) return;
    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast->next->next == head) {
        fast = fast->next;
    }

    *head1_ref = head;
    if (head->next != head) {
        *head2_ref = slow->next;
    }
    fast->next = *head2_ref;
    slow->next = *head1_ref;
}

int main() {
    // Test implementation for splitting
    return 0;
}