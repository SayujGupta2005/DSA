
// LuvBabbar_lec-28

// Refernce variable = same memory box, different variables

#include<bits/stdc++.h>
using namespace std;

void update(int &n){
    n++;
}

int main(){

    int i=5;
    int &j=i;

    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;

//Usually in functions,like in the update function,a copy is made of the input variable
//and the copy is passed to the function. But in case of reference variables,
//the actual variable is passed to the function. So, the variable is updated

    update(j);
    cout<<j<<endl;
    return 0;

}

// DYNAMIC MEMORY

// When we initialize a variable , char ch= a;int i=9;int b=9 ,this is all done in stack memory
// But when we declare a variable like 
//          int *p=new int(9);
// , this is done in heap memory

//The size of int *p (left hand side ) =8 (bcoz its a pointer) and is in STACK MEMORY
//The size of right hand side is in HEAP MEMORY
//total size= lhs+rhs


#include<bits/stdc++.h>
using namespace std;

int getsum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){

    int n;
    cin>>n;
    int *p=new int[n];

    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    int sum=getsum(p,n);
    cout<<sum<<endl;

    return 0;

}

//Static Memory vs Dynamic Memory

// an array of 50 integers will have:
// 50 * 4 bytes = 200 bytes in stack in static memory
// 50 * 4 bytes = 200 bytes in stack and 8 bytes in heap in dynamic memory