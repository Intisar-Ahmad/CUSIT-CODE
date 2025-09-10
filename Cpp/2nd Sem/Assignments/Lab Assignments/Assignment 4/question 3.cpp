#include <iostream>
#include <string>
using namespace std;


class Person {
protected:
    int id;
    string name;
public:
    Person(int i, string n) : id(i), name(n) {}
    void displayInfo() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};


class Staff : public Person {
public:
    Staff(int i, string n) : Person(i, n) {}
};


class Librarian : public Staff {
public:
    Librarian(int i, string n) : Staff(i, n) {}
    void manageBooks() {
        cout << "Managing books" << endl;
    }
};


class Book {
public:
    string title;
    string author;
};


class Library {
    string name;
    Book books[5];
    int count = 0;
public:
    Library(string n) : name(n) {}

    void addBook(Book b) {
        if (count < 5) {
            books[count++] = b;
        } else {
            cout << "Library full, cannot add more books." << endl;
        }
    }

    void showBooks() {
        cout << "Books in " << name << ":" << endl;
        for (int i = 0; i < count; i++) {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
};
