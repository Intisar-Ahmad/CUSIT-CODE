#include <iostream>

using namespace std;

class Sales {
protected:
    float sales[3];
public:
    void getData() {
        cout << "Enter sales for last 3 months:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": $";
            cin >> sales[i];
        }
    }
    void putData() const {
        cout << "Sales for last 3 months: ";
        for (int i = 0; i < 3; i++) {
            cout << "$" << sales[i] << " ";
        }
        cout << endl;
    }
};

class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore();  // flush newline
        getline(cin, title);
        cout << "Enter price: $";
        cin >> price;
    }
    void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getData();
    }
    void putData() const {
        Publication::putData();
        cout << "Page Count: " << pageCount << endl;
        Sales::putData();
    }
};

class Tape : public Publication, public Sales {
private: 
float playTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playTime;
        Sales::getData();
    }
    void putData() const {
        Publication::putData();
        cout << "Playing Time: " << playTime << " mins" << endl;
        Sales::putData();
    }
};

int main() {
    Book b;
    Tape t;

    cout << "\nEnter Book Info:\n";
    b.getData();

    cout << "\nEnter Tape Info:\n";
    t.getData();

    cout << "\n--- Book Info ---\n";
    b.putData();

    cout << "\n--- Tape Info ---\n";
    t.putData();

    return 0;
}
