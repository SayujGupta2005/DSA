// LuvBabbar_lec-28

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n]; //This way of initialising an array is bad
    //We should always make an array like a[1000001]

    //This is because there are 2 types of memories:
        // 1)Stack , 2)Heap
    //We've been utilising stack memory so far
    //When we press compile, some amount of stack memory is alloted to us
    //But a[n] will be initialised after we have taken n during runtime
    //If value of n is so large that the array initialised is larger than stack,our program will crash
    //Thus we initialise array beforehand so that stack memory is alloted taking the size of array in mind
    

}