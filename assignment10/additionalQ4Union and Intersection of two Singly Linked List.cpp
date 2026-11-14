#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper function to append node to a list
void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

void findUnionAndIntersection(Node* head1, Node* head2, Node*& unionHead, Node*& intersectionHead) {
    unordered_set<int> set1;
    unordered_set<int> visitedUnion;
    
    Node* curr = head1;
    while (curr) {
        set1.insert(curr->data);
        curr = curr->next;
    }
    
    curr = head2;
    while (curr) {
        if (set1.count(curr->data)) {
            // Found in intersection
            append(intersectionHead, curr->data);
        }
        curr = curr->next;
    }
    
    // Build union list
    curr = head1;
    while (curr) {
        if (visitedUnion.find(curr->data) == visitedUnion.end()) {
            append(unionHead, curr->data);
            visitedUnion.insert(curr->data);
        }
        curr = curr->next;
    }
    
    curr = head2;
    while (curr) {
        if (visitedUnion.find(curr->data) == visitedUnion.end()) {
            append(unionHead, curr->data);
            visitedUnion.insert(curr->data);
        }
        curr = curr->next;
    }
}

int main() {
    Node* head1 = nullptr;
    append(head1, 10); append(head1, 15); append(head1, 4); append(head1, 20);
    
    Node* head2 = nullptr;
    append(head2, 8); append(head2, 4); append(head2, 2); append(head2, 10);
    
    Node* unionHead = nullptr;
    Node* intersectionHead = nullptr;
    
    findUnionAndIntersection(head1, head2, unionHead, intersectionHead);
    
    cout << "Intersection List: ";
    printList(intersectionHead);
    cout << "Union List: ";
    printList(unionHead);
    
    return 0;
}