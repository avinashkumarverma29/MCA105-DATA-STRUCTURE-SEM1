#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;
    ListNode* current = head;
    
    while (current != nullptr) {
        if (visited.count(current)) {
            return true;
        }
        visited.insert(current);
        current = current->next;
    }
    return false;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> (points back to 2)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Loop here

    cout << (hasCycle(head) ? "true" : "false") << endl;
    return 0;
}