#include<bits/stdc++.h>
using namespace std;
//if we have to find the sqrt of 16 and we are given a vector from 0 to 16
//Then we'll take mid no ie 8 and see if 8*8 is > or < 16
//As it is >16 so we'll make our high=8 and then take mid of 0 and 8 ie 4
// 4*4==16 so 4 is the sqrt of 16
int eps =1e-1;
int func(int n){
    int lo=0,hi=n;
    while(hi-lo>eps){
        int mid=(lo+hi)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid>n){
            hi=mid;

        }
        else{
            lo=mid;
        }
    }
    return -1;
}

int main(){
    int element;
    cin>>element;
    cout<<func(element)<<endl;
    return 0;
}