#include<iostream>

using namespace std;

int main()
{
    int* arr0 = new int[20]{2,4,6,8,10,12,14,16,18,20};
    int* arr1 = new int[10]{22,24,26,28,30};
    int* arr2 = new int[5]{32,33,34,36,38};
    
    
//     for (int i = 0; i < 10; i++)
//     {
//         cout << arr1[i] << endl;
//     }
    


    for(int i = 0;i < 5;i++){
            arr1[5+i] = arr2[i];
            }
            

    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
    
    cout << endl;

    for(int i = 0;i < 10;i++){
            arr0[10+i] = arr1[i];
            }
            
            
    for(int i = 0;i<20;i++){
            cout << arr0[i] << " ";
        }

        cout << endl;
    return 0;
}
