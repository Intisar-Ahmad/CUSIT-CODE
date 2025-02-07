#include<iostream>

using namespace std;

int main(){
    //Finding a specific value in a 2D array
    int target = 6;
    int arr[2][3] = {{4,2,7},{6,8,9}};
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if(arr[row][col] == target){
                cout<<"Target is at row "<<row<<" and column "<<col<<endl;
                break;
            }
        }
        
    }
    
    return 0;
}