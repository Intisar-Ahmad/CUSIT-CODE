#include<iostream>

using namespace std;

class Product{

public:
string name;
string date;
int quantity;
double price;
static int totalcount;


Product(string name,string date,int quantity,double price):name{name},date{date},quantity{quantity},price{price}{
    totalcount++;
}


    void display(){
        cout<<name<<endl;
        cout<<date<<endl;
        cout<<quantity<<endl;
        cout<<price<<endl;
    }

    static int getTotalCount(){
        return totalcount;
    }

};

int Product :: totalcount = 0;

int main(){
    Product p1("name1","date",3,34);
    Product p2("name2","date",3,34);
    Product p3("name3","date",3,34);
    Product p4("name4","date",3,34);
    Product p5("name5","date",3,34);
    Product p6("name6","date",3,34);
    // Product p7("name7","date",3,34);


    cout<<p1.getTotalCount();

    Product::getTotalCount();


    return 0;
}