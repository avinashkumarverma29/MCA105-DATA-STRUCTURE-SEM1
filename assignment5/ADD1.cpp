#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;

    Node* ptrA = headA;
    Node* ptrB = headB;

    while (ptrA != ptrB) {
        ptrA = ptrA == nullptr ? headB : ptrA->next;
        ptrB = ptrB == nullptr ? headA : ptrB->next;
    }
    return ptrA;
}

int main() {
    // Creating intersecting lists manually
    Node* common = new Node{8, new Node{5, nullptr}};
    
    Node* headA = new Node{4, new Node{1, common}};
    Node* headB = new Node{5, new Node{6, new Node{1, common}}};

    Node* intersection = getIntersectionNode(headA, headB);
    if (intersection)
        cout << "Intersected at " << intersection->data << "\n";
    else
        cout << "No intersection\n";

    return 0;
}