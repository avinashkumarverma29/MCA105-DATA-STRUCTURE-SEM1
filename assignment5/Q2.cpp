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

void countAndDeleteKey(Node*& head, int key) {
    int count = 0;
    
    // Remove all occurrences at the beginning
    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }

    cout << "Count: " << count << "\n";
    cout << "Updated Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << (temp->next ? "->" : "");
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int x : arr) append(head, x);

    int key = 1;
    cout << "Key: " << key << "\n";
    countAndDeleteKey(head, key);

    return 0;
}