#include<bits/stdc++.h>
using namespace std;

/* THIS IS THE WRING WAY BECAUSE OF EXPONENTIAL TIME COMPLEXITY

// bool isPrime(int n){
//     if(n <= 1) return false;

//     for(int i{2};i<n;i++){
//         if(n%i == 0) return false;
//     }

//     return true;
// }


// int main(){
//     int n;
//     cin>>n;
//     int count =0;
//     if(n>=2){
//     count =1;
//     }
//     else{
//     }
//     int i{3};
//     while(i<n){
//         if(isPrime(i)){
//             count++;
//         }
//         i+=2;
//     }
//     cout<<count;
//     return 0;
// }
*/


//SO WE'LL USE SIEVE OF ERATOSTHENES
class Solution {
public:
    int countPrimes(int n) {
        int t=sqrt(n)+1;

    vector<bool> arr(n+1,true);
    arr[0]=arr[1]=false;
    int count =0;
    for(int i{2};i<t;i++){
        if(arr[i]){
            int j=2*i;
            while(j<n){
                arr[j]=false;
                j+=i;
            }
        }
    }
    for(int i{2};i<n;i++){
        if(arr[i]){
            count++;
        }
    }
    return count;
        
    }
};

