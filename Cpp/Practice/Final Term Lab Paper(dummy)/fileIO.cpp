#include <iostream>
#include<fstream>
using namespace std;

const string path = "D://Cpp-Cusit//Practice/";

int main() {
    ofstream file(path + "bhino.txt");
    if(file.is_open()){
        cout<< "file is open" << endl;
        file << "bhino is cool. I don't care what fahad zia says.";
        file.close();
    }


    // reading from a file
    ifstream fileRead(path + "bhino.txt");
    if(fileRead.is_open()){
        cout<< " file is open for reading" << endl;
        string line;
        while(getline(fileRead, line)){
            cout << line << endl;
        }
        fileRead.close();
    }

    // appending to a file 
    ofstream fileAppend(path + "bhino.txt", ios::app);
    if(fileAppend.is_open()){
        cout << "file is open for appending" << endl;
        fileAppend << "\nI am appending this line to the file.";
        fileAppend.close();
    }
    
    return 0;
}