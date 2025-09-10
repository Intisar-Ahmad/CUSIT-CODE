#include <iostream>
#include<fstream>
#include<cstdio>
using namespace std;


int main() {
    // ofstream file("hello.cpp");
    // if(file.is_open()){
    //     file << "#include<iostream>\n";
    //     file << "\n using namespace std;";
    //     file << "\n int main(){\n";
    //     file << " cout<<\" hello world\"\n";
    //     file << "return 0;\n";
    //     file << "\n }";
    //     cout<< "file written successfully"<< endl;
    //     file.close();
    // }
    ifstream fileRead("hello.cpp");
    string n;
    if(fileRead.is_open()){
        while(getline(fileRead,n)){
            cout<<n<<endl;
        }
        fileRead.close();
    }
  
    return 0;
}