#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() { head = NULL; }

    // Insert at Beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, NULL};
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Insert at End
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, NULL};
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Insert at Position (after given pos index)
    void insertAtPosition(int val, int pos) {
        if (!head || pos <= 0) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node{val, NULL};
        Node* temp = head;
        int count = 0;
        while (count < pos-1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete by value
    void deleteNode(int key) {
        if (!head) return;

        Node* curr = head;
        Node* prev = NULL;

        // Case 1: Head node deletion
        if (head->data == key) {
            Node* temp = head;
            while (temp->next != head) temp = temp->next; // last node
            if (head->next == head) { // only one node
                delete head;
                head = NULL;
                return;
            }
            temp->next = head->next;
            head = head->next;
            delete temp;
            return;
        }

        // Case 2: Other node deletion
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);
    }

    // Display list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cl;

    cout << "Inserting at Beginning:\n";
    cl.insertAtBeginning(10);
    cl.insertAtBeginning(5);
    cl.display();

    cout << "\nInserting at End:\n";
    cl.insertAtEnd(20);
    cl.insertAtEnd(30);
    cl.display();

    cout << "\nInserting at Position (after index 1):\n";
    cl.insertAtPosition(15, 1);  // after node at index 1
    cl.display();

    cout << "\nDeleting 20:\n";
    cl.deleteNode(20);
    cl.display();

    cout << "\nDeleting Head (5):\n";
    cl.deleteNode(5);
    cl.display();

    return 0;
}
