#include<iostream>
#include<vector>
using namespace std;

class Chai{
public:

    //data members or attributes
    string name;
    int servings;
    vector<string> ingredients;

    //member functions
    void displayDetails(){
        cout<<this->name<<endl;
        cout<<this->servings<<endl;
        for(auto ingredient : this->ingredients){
            cout<<ingredient<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Chai chai1;

    chai1.name = "Tea";
    chai1.servings = 8;
    chai1.ingredients = {"water","tea","milk"};
    chai1.displayDetails();
    return 0;
}