#include <iostream>
using namespace std;

// --- Doubly Linked List Implementation ---
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << val << " at the beginning.\n";
    }

    void insertLast(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            cout << "Inserted " << val << " as the first node.\n";
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << val << " at the end.\n";
    }

    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp && temp->data != target) temp = temp->next;
        if (!temp) {
            cout << "Target node not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << val << " after " << target << ".\n";
    }

    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp && temp->data != val) temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else {
            temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
        }
        delete temp;
        cout << "Deleted node with value " << val << ".\n";
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// --- Circular Singly Linked List Implementation ---
class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* tail; // pointing to the last node

public:
    CircularLinkedList() : tail(nullptr) {}

    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
        cout << "Inserted " << val << " at the beginning.\n";
    }

    void insertLast(int val) {
        insertFirst(val);
        tail = tail->next;
    }

    void deleteNode(int val) {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }
        Node* curr = tail->next;
        Node* prev = tail;
        do {
            if (curr->data == val) {
                if (curr == tail && curr->next == tail) {
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == tail) tail = prev;
                }
                delete curr;
                cout << "Deleted node with value " << val << ".\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Node not found!\n";
    }

    bool search(int val) {
        if (!tail) return false;
        Node* curr = tail->next;
        do {
            if (curr->data == val) return true;
            curr = curr->next;
        } while (curr != tail->next);
        return false;
    }

    void display() {
        if (!tail) {
            cout << "CLL is empty.\n";
            return;
        }
        Node* curr = tail->next;
        cout << "CLL: ";
        do {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != tail->next);
        cout << "(head repeated: " << tail->next->data << ")\n";
    }
};

int main() {
    // Menu driver skeleton can be called here for testing DLL and CLL operations.
    cout << "Q1 Menu-driven template ready.\n";
    return 0;
}