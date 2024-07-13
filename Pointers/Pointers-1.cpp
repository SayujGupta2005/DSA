// Luvbabbar_lec-25

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    //address operator- &
    cout<<"address of num is- "<<&n<<endl;
    //pointer=stores address
    int *p = &n;
    //p is a pointer to int datatype i.e. the datatype of right-side
    //p stores the memory address of n
    //*p stores the data in the memory address pointed to by p

    //Size of pointer will always be 8

    char cs='s';
    char *ch = &cs;
    cout<<"p: "<<p<<endl<<"*p: "<<*p<<endl;


    //copying a ptr
    int *q=p;
    cout<<q<<' '<<p<<endl;
    cout<<*q<<' '<<*p;
    return 0;
}