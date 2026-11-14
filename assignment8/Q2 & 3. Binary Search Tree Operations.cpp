#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 3(a) Insert (No duplicates allowed)
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// 2(a) Search (Recursive)
Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// 2(a) Search (Non-Recursive)
Node* searchIterative(Node* root, int key) {
    while (root && root->data != key) {
        root = (key < root->data) ? root->left : root->right;
    }
    return root;
}

// 2(c) Minimum Element
Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

// 2(b) Maximum Element
Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

// 2(d) In-order Successor
Node* inOrderSuccessor(Node* root, Node* target) {
    if (target->right) return findMin(target->right);
    Node* succ = nullptr;
    while (root) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

// 2(e) In-order Predecessor
Node* inOrderPredecessor(Node* root, Node* target) {
    if (target->left) return findMax(target->left);
    Node* pred = nullptr;
    while (root) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}

// 3(b) Delete an existing element
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 3(c) Maximum Depth
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// 3(d) Minimum Depth
int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = nullptr;
    int vals[] = {50, 30, 20, 40, 70, 60, 80};
    for (int v : vals) root = insert(root, v);

    Node* target = searchRecursive(root, 40);
    if (target) {
        Node* succ = inOrderSuccessor(root, target);
        Node* pred = inOrderPredecessor(root, target);
        cout << "40 -> Pred: " << (pred ? pred->data : -1) 
             << ", Succ: " << (succ ? succ->data : -1) << "\n";
    }

    cout << "Max Depth: " << maxDepth(root) << ", Min Depth: " << minDepth(root) << "\n";
    root = deleteNode(root, 50);
    cout << "New Root after deleting 50: " << root->data << "\n";
    return 0;
}