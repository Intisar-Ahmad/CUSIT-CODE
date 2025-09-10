#include <iostream>

using namespace std;

int main() {
    try
    {
        string x = "bhino is crazy";
     
        //   throw runtime_error("bhino is pagal");
        5/0;
        //regular code
    }
    catch(exception e){
       cout<<"fuck you" << e.what()<<endl;
    }
    catch(int e){
       cout << e << endl;
    }
    catch(string e){
        cout << e << endl;
    }
    catch(...){
        cout << "unknown error happened" << endl;
    }

    cout << "code is still running" << endl;
   
    
    return 0;
}