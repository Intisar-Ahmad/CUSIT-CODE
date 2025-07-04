#include <iostream>

using namespace std;

class GameProfile{
    private:
    int score;
    string playerName;

    public:

    GameProfile(string n,int s):score(s),playerName(n){}

    friend void checkPlayerRank();


};

void checkPlayerRank(){
    GameProfile p("Intisar Ahmad",500);
    if(p.score >= 1000){
        cout << "Pro Player" << endl;
    }
    else {
        cout << "Needs Practice" << endl;
    }
}

int main() {
    checkPlayerRank();
    return 0;
}