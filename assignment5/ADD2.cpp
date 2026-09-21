#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

Node* reverseKGroup(Node* head, int k) {
    Node* cursor = head;
    int count = 0;
    while (cursor != nullptr && count < k) {
        cursor = cursor->next;
        count++;
    }

    if (count == k) {
        Node* current = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;
        for (int i = 0; i < k; ++i) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head->next = reverseKGroup(current, k);
        return prev;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << (temp->next ? "→" : "");
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int x : arr) append(head, x);

    int k = 3;
    cout << "Original: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Result: ";
    printList(head);

    return 0;
}