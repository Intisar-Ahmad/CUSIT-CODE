#include <iostream>

using namespace std;

class Book{
    public:
    string title;
    string author;

};

class Publisher{
    public:
    int publicationYear;
};

class PrintedBook:public Book,public Publisher{
    public:
   
};

class SpecialEdition:public PrintedBook{
    public:
    int limitedCopies;



    void displaySpecs(){
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "limitedCopies: " << limitedCopies << endl;
    }
};

int main() {
    SpecialEdition book;
    book.author = "Intisar Ahmad";
    book.limitedCopies = 3;
    book.title = "How to learn C++";
    book.publicationYear = 2025;


    book.displaySpecs();
    return 0;
}