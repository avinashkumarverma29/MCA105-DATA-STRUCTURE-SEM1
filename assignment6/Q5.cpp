#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head; // Makes it circular

    cout << (isCircular(head) ? "True" : "False") << endl;
    return 0;
}