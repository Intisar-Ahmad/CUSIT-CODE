#include <iostream>
using namespace std;

/*
Task 3: Create a class OnlineOrder with the following
attributes:
• name
• quantity
• price
• orderDate
• address
Requirements:
1. Use a parameterized constructor to initialize all attributes when creating an object.
2. Implement a method displayOrder(); to print the order details and calculate the total price
*/

class OnlineOrder {
private:
    string name;
    int quantity;
    float price;
    string orderDate;
    string address;

public:
    OnlineOrder(string n, int q, float p, string date, string addr)
        : name(n), quantity(q), price(p), orderDate(date), address(addr) {}


    void displayOrder() {
        cout << "Order Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per item: $" << price << endl;
        cout << "Order Date: " << orderDate << endl;
        cout << "Delivery Address: " << address << endl;
        cout << "Total Price: $" << quantity * price << endl;
    }
};

int main() {
    OnlineOrder order1("Laptop", 2, 799.99, "2025-03-25", "Dalazak Road, Peshawar");

    order1.displayOrder();

    return 0;
}
