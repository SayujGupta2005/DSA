// Luvbabbar_lec=26

#include<bits/stdc++.h>
using namespace std;

void print(int *p){
    cout<<*p<<endl; // value of p will be printed
                    // if no * then address 
}

void update (int *p){
    /*
    
    p=p+1
    
    */;
    //This updated value of p(address) will be inside function only
    //so after calling the function,memory address of p will be same as earlier
    //but if we do cout<<p inside the function , then address would've been incremented but only inside function

    // *p++; This is equal to *(p++)
    *p=*p+1;

    // Although the value of data increased is permanent bcoz we are affecting the data stored in memory 

}


int getsum(int *p){
    return 0;
}


int main(){
    //The address of first memory block of an array is the name of the array;
    int arr[10];
    arr[0]=9;
    int *p=&arr[0];
    cout<<p<<endl;
    cout<<arr<<endl;//We can see that both the memory are same

    //So value of *arr == arr[0]
    cout<<*arr<<endl;
    cout<<arr[0]<<endl;

    // If *p=&arr[0] then p+1==&arr[1] ,so *(p+1)==arr[1]

    /*
    
    Very important:

        arr[i]=*(arr+i)
    so we can also say that 
        i[arr]=*(i+arr)
    so if we run cout<<i[arr] , we'll actually run *(i+arr)
   */

    int arr2[4]={2,5,6,7};
    int i=3;
    cout<<i[arr2]<<endl;
    
    // &p = address of pointer
    // p = address of the block that p is pointing to
    //*p= data in block

    //  Char arrays

    // cout has different implementation incase of integer and character
    // cout<<arr<<endl; //prints the address of the first block
    // cout<<arr3<<endl; //prints the entire array

    char arr3[5]={'a','b','c','d','e'};
    char *p3=arr3;
    char *p4=&arr3[0];
    cout<< p3<<" "<< p4 <<endl;
    cout<< *p3<<" "<<*p4<<endl;


    char temp='z';
    char *p5=&temp;
    cout<<p5<<endl; // although temp has just 'z',cout won't stop printing until it finds a null value
                    //so after printing 'z',the pointer will keep on moving forward in the memory until it finds null 
    
    //Functions

    int value=5;
    int *p6=&value;
    
    print(p6);

    cout<<p6<<endl;
    update(p6);
    cout<<p6<<endl;
    cout<<*p6<<endl;
    
    // when we pass an arary in a function, like func(int arr[]), what we're actually doing is passing 
    // the address of the first block of the array to the function. So, int arr[]== int *arr
    // so if we call cout<<sizeof(arr), we get 8 i.e. size of the pointer although we expect no of blocks*size of int 
    
    return 0;
}