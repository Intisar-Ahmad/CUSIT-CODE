#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class shopkeeper; // Forward declaration

class product {
private:
    string ItemName;
    int quantity;
    float UnitPrice;

public:
    product() {
        ItemName = "";
        quantity = 0;
        UnitPrice = 0.0;
    }

    friend void invoice(product p[], shopkeeper s[], int pCount, int sCount);
};

class shopkeeper {
private:
    string SkName;
    string location;
    string phoneNumber;

public:
    shopkeeper() {
        SkName = "";
        location = "";
        phoneNumber = "";
    }

    friend void invoice(product p[], shopkeeper s[], int pCount, int sCount);
};

void invoice(product p[], shopkeeper s[], int pCount, int sCount) {
    ofstream fout("invoice.txt");

    if (!fout) {
        cout << "Error opening file!" << endl;
        return;
    }

    fout << "******** BILL INVOICE ********\n";

    for (int i = 0; i < sCount; ++i) {
        cout << "\nEnter details for shopkeeper " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, s[i].SkName);
        cout << "Location: ";
        getline(cin, s[i].location);
        cout << "Phone Number: ";
        getline(cin, s[i].phoneNumber);

        fout << "\nShopkeeper: " << s[i].SkName
             << "\nLocation: " << s[i].location
             << "\nPhone: " << s[i].phoneNumber << "\n";

        for (int j = 0; j < pCount; ++j) {
            cout << "\nEnter details for product " << j + 1 << ":\n";
            cout << "Item Name: ";
            getline(cin, p[j].ItemName);
            cout << "Quantity: ";
            cin >> p[j].quantity;
            cout << "Unit Price: ";
            cin >> p[j].UnitPrice;
            cin.ignore(); // clear buffer

            fout << "Product: " << p[j].ItemName
                 << ", Quantity: " << p[j].quantity
                 << ", Unit Price: " << p[j].UnitPrice
                 << ", Total: " << p[j].quantity * p[j].UnitPrice << "\n";
        }
        fout << "-----------------------------\n";
    }

    fout.close();
    cout << "\nInvoice saved to 'invoice.txt'\n";
}

void readInvoice() {
    ifstream fin("invoice.txt");
    if (!fin) {
        cout << "Could not open invoice file!" << endl;
        return;
    }

    cout << "\n***** STORED INVOICE DATA *****\n";
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

int main() {
    shopkeeper s[2]; // saad, khan
    product p[2];    // Pepsi, Sting

    invoice(p, s, 2, 2);
    readInvoice();

    return 0;
}
