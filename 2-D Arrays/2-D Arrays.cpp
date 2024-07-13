// LuvBabbar_lec-23

// In a memory, a 2-D array is stored as a linear array(fuddu kat rha tha ab tak!!)

//To convert a  2d array of m rwos and n columns into 1d, we'll 
//use the formula: 1d array index = (row index * n) + column index


//To convert a 1-d array back to 2-d array
//we'll use the formula: row index = 1d array index / n
//column index = 1d array index % n

//Input and Output of 2-D array 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[3][3];
    for(int i{0};i<3;i++){
        for(int j{0};j<3;j++){
            cin>>arr[i][j];
        }
    }
    for(int i{0};i<3;i++){
        for(int j{0};j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //Finding an element in array
    int n;
    cin>>n;
    bool found=false;
    for(int i{0};i<3;i++){
        for(int j{0};j<3;j++){
            if(arr[i][j]==n){
                cout<<"Element found at "<<i<<" "<<j<<endl;
                found=true;
                break;
            }
            if(found)break;
        }

    } 

    //Binary Search in 2-D arrays
       //Convert the above 2-d array into 1-d and apply binary search
        //if possible
    
    return 0;
}