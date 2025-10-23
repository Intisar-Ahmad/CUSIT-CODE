#include <iostream>

using namespace std;

class GPSCoordinate
{
public:
    int x, y;
    bool isTracking = false;
};

class Location
{
public:
    int id;
    GPSCoordinate coord;
};

class Order
{
public:
    string orderId;
    Location loc;
    string orderItem;
};

class Node
{
public:
    Order ord;
    Node *next = NULL;
};

class List
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    // append
    void append(const Order &order)
    {
        Node *newNode = new Node();
        newNode->ord = order;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // traverse

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->ord.orderId << endl;
            cout << temp->ord.orderItem << endl;
            cout << temp->ord.loc.id << endl;
            cout << temp->ord.loc.coord.x << endl;
            cout << temp->ord.loc.coord.y << endl;
            cout << temp->ord.loc.coord.isTracking << endl;

            temp = temp->next;
        }
    }

    // display with gps
    void displayGPS()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->ord.loc.coord.isTracking == true)
            {
                cout << temp->ord.orderId << endl;
                cout << temp->ord.orderItem << endl;
                cout << temp->ord.loc.id << endl;
                cout << temp->ord.loc.coord.x << endl;
                cout << temp->ord.loc.coord.y << endl;
                cout << temp->ord.loc.coord.isTracking << endl;
            }
            temp = temp->next;
        }

    }

    // removing through id
    void removeNodeByLocationId(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        if (head->ord.loc.id == id)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        else if (tail->ord.loc.id == id)
        {
            Node *temp = head;
            Node *prev = NULL;

            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = temp->next;
            tail = prev;
            delete temp;
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;
            while (temp != NULL && temp->ord.loc.id != id)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Order not found\n";
                return;
            }

            if (temp->ord.loc.id == id)
            {
                prev->next = temp->next;
                delete temp;
            }
        }
    }
};

int main()
{

    Order ord1;
    ord1.orderId = "order1";
    ord1.orderItem = "banana";
    ord1.loc.id = 111;
    ord1.loc.coord.isTracking = false;
    ord1.loc.coord.x = 5;
    ord1.loc.coord.y = 6;

    Order ord2;
    ord2.orderId = "order2";
    ord2.orderItem = "apples";
    ord2.loc.id = 222;
    ord2.loc.coord.isTracking = true;
    ord2.loc.coord.x = 6;
    ord2.loc.coord.y = 5;

    List list;

    list.append(ord1);
    list.append(ord2);

    list.display();

    list.displayGPS();

    list.removeNodeByLocationId(111);

    list.display();

    return 0;
}
