
//Double Pointers

#include<bits/stdc++.h>
using namespace std;

int main(){

    int i{5};
    int* p=&i;
    int** p2=&p;

    // p=&i
    // p2=&p
    // *p2==p==&i
    // **p2==*p==i

    // Now in a function if do p2=p2+1 -> No Effect
    // But if we do *p2=*p2+1 -> then p i.e. &i will increase by1 although it'll have the same value
    //                                      and everything else will also work (just the memory 
    //                                      address will increase by 4 bytes)



    /*
    Important MCQs
    */

    int a=8;
    int b=9;
    int *ptr=&b;
    *ptr=18;
    cout<<a<<" "<<b<<endl; //Ans will be 8 and 18


    return 0;
}