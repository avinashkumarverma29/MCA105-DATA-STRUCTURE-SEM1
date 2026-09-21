#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void displayCircularWithHeadRepeat(Node* tail) {
    if (!tail) return;
    Node* head = tail->next;
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << head->data << endl; // Repeat head at the end
}

int main() {
    // Constructing: 20 -> 100 -> 40 -> 80 -> 60 -> (back to 20)
    Node* head = new Node(20);
    head->next = new Node(100);
    head->next->next = new Node(40);
    head->next->next->next = new Node(80);
    head->next->next->next->next = new Node(60);
    Node* tail = head->next->next->next->next;
    tail->next = head;

    displayCircularWithHeadRepeat(tail);
    return 0;
}