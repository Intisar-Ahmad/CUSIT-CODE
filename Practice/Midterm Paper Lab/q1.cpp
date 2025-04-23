#include<iostream>

using namespace std;

class Library
{
private:
    int id ;
    string fullName ;
    string memberShipType;
    int booksIssued;
public:
    Library():id{0},fullName{""},memberShipType{""},booksIssued{0}{
        
    }

    void setFullname(string name){
        if(name.length() == 0){
            cout<<"name cannot be empty"<<endl;
        }
        else{
            fullName = name;
        }
    }

    void setMembership(string membership){
        if(!(membership == "standard" || membership == "premium" || membership == "vip")){
            cout<<"membership type is invalid"<<endl;
        }
        else{
            memberShipType = membership;
        }
    }

    void setBooksIssued(int books){
        if(books < 0){
            cout<<"books issued cannot be negative"<<endl;
        }
        else{
            booksIssued = books;
        }
    }

    //implement getters

    void display(){
        cout<<"ID: "<<id<<endl;
        cout<<"Full Name: "<<fullName<<endl;
        cout<<"Membership Type: "<<memberShipType<<endl;
        cout<<"Books Issued: "<<booksIssued<<endl;
    }
 
};




int main(){
    Library l1;
    l1.setFullname("John Doe");
    l1.setBooksIssued(5);
    l1.setMembership("premium");
    l1.display();
    return 0;
}