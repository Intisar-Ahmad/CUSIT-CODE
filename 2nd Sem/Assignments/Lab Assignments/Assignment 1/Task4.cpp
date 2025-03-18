#include<iostream>

using namespace std;

/*
Task 4: Create a class Book with the following
attributes:
• name
• author
• price
Requirements:
• Implement a method displayBookData() that prints book details.
• After assigning values to a Book object, call displayBookData().
*/

class Book{
    public:
    string name;
    string author;
    float price;

    void displayBookData(){
        cout<<"Name: "<<name<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

int main(){
    Book book1;
    book1.name = "The Alchemist";
    book1.author = "Paulo Coelho";
    book1.price = 9.99;

    book1.displayBookData();
    return 0;
}
