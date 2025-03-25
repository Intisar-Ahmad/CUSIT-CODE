#include <iostream>
using namespace std;
/*
Task 1: Create a class Book with the following attributes:
• title
• author
• genre
• publicationYear
Requirements:
1. Use a default constructor to initialize the following default values:
2. Implement a method displayBook(); to print the book's details
*/

class Book {
private:
    string title;
    string author;
    string genre;
    int publicationYear;

public:
    // Default constructor with default values
    Book() : title("Learning to Code"), author("Intisar Ahmad"), genre("Programming"), publicationYear(2025) {}

    // Method to display book details
    void displayBook() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "Publication Year: " << publicationYear << endl;
    }
};

int main() {
    Book myBook;  
    myBook.displayBook(); 

    return 0;
}
