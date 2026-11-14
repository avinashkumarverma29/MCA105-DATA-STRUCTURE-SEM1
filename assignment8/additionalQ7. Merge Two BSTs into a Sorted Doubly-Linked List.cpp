#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right; // left = prev, right = next in DLL
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Convert BST to Sorted Doubly Linked List in-place
void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;
    bstToDLL(root->left, head, prev);

    if (!prev) {
        head = root;
    } else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

// Merge two sorted Doubly Linked Lists
Node* mergeDLL(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head = nullptr;
    Node* tail = nullptr;

    while (head1 && head2) {
        Node* chosen = nullptr;
        if (head1->data <= head2->data) {
            chosen = head1;
            head1 = head1->right;
        } else {
            chosen = head2;
            head2 = head2->right;
        }

        if (!head) {
            head = tail = chosen;
            chosen->left = nullptr;
        } else {
            tail->right = chosen;
            chosen->left = tail;
            tail = chosen;
        }
    }

    Node* rem = head1 ? head1 : head2;
    while (rem) {
        tail->right = rem;
        rem->left = tail;
        tail = rem;
        rem = rem->right;
    }
    return head;
}

Node* mergeTwoBSTs(Node* root1, Node* root2) {
    Node *head1 = nullptr, *prev1 = nullptr;
    Node *head2 = nullptr, *prev2 = nullptr;

    bstToDLL(root1, head1, prev1);
    bstToDLL(root2, head2, prev2);

    return mergeDLL(head1, head2);
}

int main() {
    Node* T1 = new Node(20);
    T1->left = new Node(10);
    T1->right = new Node(30);
    T1->right->left = new Node(25);
    T1->right->right = new Node(100);

    Node* T2 = new Node(50);
    T2->left = new Node(5);
    T2->right = new Node(70);

    Node* mergedHead = mergeTwoBSTs(T1, T2);
    while (mergedHead) {
        cout << mergedHead->data << " <-> ";
        mergedHead = mergedHead->right;
    }
    cout << "null\n";
    return 0;
}