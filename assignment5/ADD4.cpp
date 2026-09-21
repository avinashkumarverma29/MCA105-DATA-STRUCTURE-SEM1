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

Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    tail->next = head; // Make it circular
    Node* newTail = head;
    for (int i = 1; i < k; ++i) {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = nullptr;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int arr[] = {10, 20, 30, 40, 50};
    for (int x : arr) append(head, x);

    int k = 4;
    cout << "Original head 10 20 30 40 50 NULL\n";
    head = rotateLeft(head, k);

    cout << "Output: head ";
    printList(head);

    return 0;
}