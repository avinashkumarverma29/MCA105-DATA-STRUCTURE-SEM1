#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() { head = nullptr; }

    // (a) Insertion at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning.\n";
    }

    // (b) Insertion at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << val << " at the end.\n";
    }

    // (c) Insertion in between (before or after a specific value)
    void insertInBetween(int targetVal, int val, bool insertBefore) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (insertBefore && head->data == targetVal) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        if (insertBefore) {
            while (temp->next != nullptr && temp->next->data != targetVal) {
                temp = temp->next;
            }
            if (temp->next == nullptr) {
                cout << "Target value not found.\n";
                return;
            }
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << " before " << targetVal << ".\n";
        } else { // insertAfter
            while (temp != nullptr && temp->data != targetVal) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Target value not found.\n";
                return;
            }
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << " after " << targetVal << ".\n";
        }
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from the end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << "Deleted " << temp->next->data << " from the end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Deletion of a specific node
    void deleteSpecificNode(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Node with value " << val << " not found.\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted node with value " << val << ".\n";
        delete nodeToDelete;
    }

    // (g) Search for a node and display its position from head (1-indexed)
    void searchNode(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position: " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << val << " not found in the list.\n";
    }

    // (h) Display all the node values
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, target;
    char posChoice;

    do {
        cout << "\n--- SINGLY LINKED LIST MENU ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert in between\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete specific node\n";
        cout << "7. Search node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter target value: "; cin >> target;
                cout << "Enter new value to insert: "; cin >> val;
                cout << "Do you want to insert before (B) or after (A)? "; cin >> posChoice;
                list.insertInBetween(target, val, (posChoice == 'B' || posChoice == 'b'));
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: "; cin >> val;
                list.deleteSpecificNode(val);
                break;
            case 7:
                cout << "Enter value to search: "; cin >> val;
                list.searchNode(val);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}