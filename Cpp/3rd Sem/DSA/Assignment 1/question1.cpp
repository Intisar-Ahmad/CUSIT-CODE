#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertFirst(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertLast(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at a specific position 
    void insertAtMiddle(int val, int pos)
    {
        if (pos < 1 || !head)
        {
            insertFirst(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        int count = 0;
        while (temp && count < pos)
        {
            temp = temp->next;
            count++;
        }
        if (!temp)
        {
            insertLast(val);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove first node with given value
    void removeNode(int val)
    {
        if (!head)
            return;
        if (head->data == val)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != val)
        {
            temp = temp->next;
        }

        if (temp->next)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }


    // Traverse and print the list
    void display() 
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

   bool seek(int val) {
    Node* temp = head;
    int index = 0;
    while (temp) {
        if (temp->data == val) {
            cout << "Found " << val << " at index " << index << endl;
            return true;
        }
        temp = temp->next;
        index++;
    }
    cout << val << " not found.\n";
    return false;
}


    // Destructor to free memory
    ~LinkedList()
    {
        Node *temp = head;
        while (temp)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Example usage

int main()
{
    LinkedList list;
    int choice, val, pos;
    while (true) {
        cout << "\nChoose operation:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Node by Value\n";
        cout << "5. Display List\n";
        cout << "6. Seek Value\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertFirst(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertLast(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position (0-based index): ";
                cin >> pos;
                list.insertAtMiddle(val, pos);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                list.removeNode(val);
                break;
            case 5:
                cout << "Linked List: ";
                list.display();
                break;
            case 6:
                cout << "Enter value to seek: ";
                cin >> val;
                list.seek(val);
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
