#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;

    // Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;
        if (slow == fast) { // Special case for loop starting at head
            while (fast->next != slow) fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = nullptr; // Remove loop
        cout << "Loop removed successfully.\n";
    } else {
        cout << "No loop found.\n";
    }
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{6, nullptr}}}};
    // Creating a loop for testing (pointing 6 back to 2)
    head->next->next->next->next = head->next;

    removeLoop(head);
    return 0;
}