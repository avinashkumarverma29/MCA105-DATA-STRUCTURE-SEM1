#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

void append(Node*& head, int c, int p) {
    Node* newNode = new Node{c, p, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* resHead = nullptr;
    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->pow > p2->pow) {
            append(resHead, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            append(resHead, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coeff + p2->coeff;
            append(resHead, sumCoeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != nullptr) {
        append(resHead, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        append(resHead, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return resHead;
}

void printPoly(Node* head) {
    Node* temp = head;
    cout << "[";
    while (temp != nullptr) {
        cout << "[" << temp->coeff << ", " << temp->pow << "]";
        if (temp->next) cout << ", ";
        temp = temp->next;
    }
    cout << "]\n";
}

int main() {
    Node* head1 = nullptr;
    append(head1, 5, 2);
    append(head1, 4, 1);
    append(head1, 2, 0);

    Node* head2 = nullptr;
    append(head2, 5, 1);
    append(head2, 5, 0);

    Node* result = addPolynomials(head1, head2);

    cout << "Output: ";
    printPoly(result);

    return 0;
}