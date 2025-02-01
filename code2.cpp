#include<iostream>
#include<vector>

using namespace std;
int main(){
    //bubble sort
    vector<int> vec = {1,1,0,2,1,0,2,2};
    bool isswap = false;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
                if(vec[j] > vec[j+1]){
                    swap(vec[j],vec[j+1]);
                    isswap = true;
                }
        }
        if(!isswap){break;}
    }

    vec = {1,1,0,2,1,0,2,2};

    // selection sort

    for (int i = 0; i < vec.size(); i++)
    {
        int minimum = i;
    for (int j = i+1; j < vec.size(); j++)
    {
        if(vec[j] < vec[minimum]){
            minimum = j;
        }
    }
    swap(vec[minimum],vec[i]);
    }
    
    vec = {1,1,0,2,1,0,2,2};
    // insertion sort

    for (int i = 0; i < vec.size(); i++)
    {
        int curr = vec[i];
        int prev = i-1;
      while(prev >= 0 && vec[prev] > curr){
        vec[prev+1] = vec[prev];
        prev--;
      }
      vec[prev+1] = curr;
    }
    

    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    
    return 0;
}