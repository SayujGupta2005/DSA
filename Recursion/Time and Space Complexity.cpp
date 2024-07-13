//Time and Space Complexity of Recursuve Functions

//Time Complexity = Worst case of time required to finish executing a function
// Space Complexity = Max space required at any instant of time

#include<bits/stdc++.h>
using namespace std;

//This function  has:
//           T.C.= O(n) {n = size of array}
//           S.C.= O(1)
bool ispresent(int value){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i{0};i<10;i++){
        if(arr[i]==value){
            return true;
        }
    }
    return false;
}

int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

bool binarysearch(int *arr,int h,int l,int k){
    if(l>h){
        return false;
        }
    int mid=h+(h-l)/2;
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]<k){
        return binarysearch(arr,h,mid+1,k);
    }
    else{
        return binarysearch(arr,mid-1,l,k);
    }
}

int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}


int main(){
    int n;
    cin>>n;
    //Linear search
    bool ans = ispresent(n); 
    // Time Complexity
    
    // 1) Recursive Factorial Function
    //For fact(n), first we'll check base case i.e. if n==0, (time taken =t1)
    //Then we'll multiply n with fact(n-1) (time taken = t2)
    //Then we'll execute fact(n-1)
    //So total time taken for fact(n)= t1 + t2 + time taken for fact(n-1)
    //Let t1+t2 =t
    //So T(n) = t + T(n-1),T(n-1) = t + T(n-2) and so on....
    //So T(n) = t + t + t + t + t + t + t
    //So T(n) = t*n
    // So T.C.=O(n) {t is constant so it can be ignored}
    
    //  2) Recursive Binary Search
    //For binary search, we'll check if mid is equal to target (time taken = t
    //First we'll check base case that is: 
    //      if l>h (time taken = t1) , if arr[mid]==k (time taken =t2)
    // Then T(n)= t1+t2+T(n/2) = t+T(n/2)
    //  T(n)= t*a {where a is no of times the function was called}
    // and we know n/(2^a)=1 so a=log(n)
    //So T(n)=t*log(n)
    // So T.C.=O(log(n))

    // 3) Merge Sort
    //For merge sort, we'll divide the array into two halves (time taken = t1)
    //Then we'll sort the two halves (time taken = t2)
    //Then we'll copy the two halves (time taken = t3*n)
    //Then we'll merge the two halves (time taken = t4*n)
    //So T(n)= t1+t2+T(n/2)+T(n/2)+t3*n+t4*n {One T(n/2) for left side of array and one for right}
    //T(n)= t + n*t + T(n/2)+T(n/2) {we'll ignore t bcoz t<<n*t} 
    //Eventually , T(n)= a*n*t {a= no of recursion = log(n)}
    // So T.C.=O(n*log(n))

    // 4) Fibonacci Series
    //First we'll take base case i.e. if n==0 ||n==1 (time taken=t1)
    //T(n)= t1+T(n-1)+T(n-2)
    //and T(n-1)=t1+T(n-2)+T(n-3),T(n-2)=t1+T(n-3)+T(n-4)
    //So T(n)=t1 + 2*t1+T(n-2)+T(n-3)+T(n-3)+T(n-4)
    //T(n)=t1+2*t1+4*t1+......
    //T(n)=(2^(n+1)-1)*t1
    // So T.C.= O(2^n)
    
    
    
    // Space Complexity
    
    // 1) Recursive Factorial Function
    //For a recursive factorial function, fact(n)=n*fact(n-1).....until we reach fact(1)
    //Thus if one fact takes 'k' amount of space then fact(n) will take:
     //                         k*n amount of space
    // So, S.C. of factorial function = O(n) {because k*n is constant, we can write as n}
     
    // 2) Recursive Binary Search
    //For an array of size n first we'll take size n, then n/2 ,then n/4,n/8....so on
    //If  size of each function is k , then total size will be:
    // k + k/2 + k/4 + k/8 + k/16 + .... = k*log(n)
    //So, S.C. of binary search function = O(log(n)) {because k is constant}

    // 3) Merge Sort
    //Size of array n
    //First we'll calculat space complexity for recursive function (that is splitting the array in 2)
    //      So we'll get total space as k*log(n)
    //Secondly, in each recursive call, we are creating a new array of size of that call's n
    //So, total space complexity will be:
    // k*log(n) + n + n/2 + n/4 + n/8
    // = k*log(n) + n*(1+1/2+1/4+)
    // = k*log(n) + n*(1-1/2^k)
    // = k*log(n) + n
    //So, S.C. of merge sort function = O(n) {because k*log(n)<<<n ,it can be ignored}
    
    // 4) Fibonacci Series
    //For a recursive fibonacci function, fib(n)=fib(n-1)+fib(n-2)
    //Thus if one fib takes 'k' amount of space then fib(n) will take:
    //                         k*n amount of space
    // So, S.C. of fibonacci function = O(n) {because k*n is constant}


    return 0;
}