//Binary Numbers

//No of bits in a binary representation of integer n = log2n +1 (log of n to the base 2)

// 1's complement of n= ~n (~ is a sign that inverses all the bits)
// 2's complement of n= ~n+1 

#include<bits/stdc++.h>
using namespace std;

void subtract(int x,int y){

    cout<<x+(~y+1)<<endl;
}

int main(){
    int x,y;
    cin>>x>>y;
    subtract(x,y);
    return 0;
}

//Swap 2 nos 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    x=x^y;
    y=x^y;
    x=x^y;
    cout<<x<<" "<<y;
    return 0;
}

/*

Bit Masking 
-- Change a bit by some mathematical use

*/
//Step-1
//Find i'th bit
//We'll left shift 1 i times and do &


#include<bits/stdc++.h>
using namespace std;

bool isOne(int n,int i){
    return (n>>i)&(1);
}

int main(){
    int n,i;
    cin>>n>>i;
    if(isOne(n,i)){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }

    return 0;
}

//Step 2
//Set i'th bit
//After finding that digit , well do | function to change the bit;
// We'll use fxns acc to the bit already present at i'th place

#include<bits/stdc++.h>
using namespace std;

bool isOne(int n,int i){
    return (n>>i)&(1);
}

int changeto1(int n,int i){
    return (n)|(1<<i);
}
int changeto0(int n,int i){
    return n^(1<<i);
}

int main(){
    int n,i;
    cin>>n>>i;
    if(!isOne(n,i)) n=changeto1(n,i);
    else n=changeto0(n,i);
    cout<<n;
    return 0;
}

//Find no fo bits to change a to b;
//We'll use xor gate
//But for efficiency, we'll do n&(n-1) which converts the last 1 to 0;
//So we'll do this till 0 and count how many times we had to this. 
//The coutn will be no of the bots required to change

/*

XOR GATE

 */

//Types of Questions
//1) Find the only non-repeating element in array where every element repeats twice
//2) Find the two non-repeating elements in an array where every element repeats twice
//3)Find the only non-repeating element in array where each element repeats k-times

//Properties:
    //if integer n, then:
    //  n^0=n
    //  n^n=0

//1) Find the only non-repeating element in array where every element repeats twice
//   Ans- XOR all the numbers and answer will be the one non-repeating
#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int result=0;
    for(int i{0};i<n;i++){
        result^=a[i];
    }
    cout<<result;

    return 0;
}

//2) Find the two non-repeating elements in an array where every element repeats twice
//   Ans- Let's say we have x and y non-repeating so using the above method, we'll get x^y as result
//        Now we'll find the index of rightmost set bit (1) and divide the whole array into two parts
//        One part will have integers with set bit at the same index and other part which won't
//        Now we'll xor the two parts separately and we'll get the answer

#include<bits/stdc++.h>
using namespace std;

bool isOne(int n,int i){
    return (n>>i)&(1);
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    int result=0;
    for(int i=0;i<n;i++){ 
        cin>>arr[i];
        result^=arr[i];
    }
    int index = 0;
    while ((result & (1 << index)) == 0) {
        index++;
    }
    vector<int> part1,part2;
    for(auto c:arr){
        if(isOne(c,index)) part1.push_back(c);
        else part2.push_back(c);
    }
    int result1=0,result2=0;
    for(auto c:part1) result1^=c;
    for(auto c:part2) result2^=c;

    cout<<result1<<" "<<result2;

    return 0;
}

//3)Find the only non-repeating element in array where each element repeats k-times
//  Ans-We'll create an array (arr) of size n with all elements set to 0(n= no of elements)
//      Then we'll traverse the input list and increase the i'th index of arr if there is 1 at i'th index of a number
//      Then we'll take modulo k of each index of arr
//      The remaining will be answer

#include<bits/stdc++.h>
using namespace std;

bool isOne(int n,int i){
    return (n>>i)&(1);
}

int main(){
    int n,k;
    cin>>n>>k;
    int input[n];
    int arr[32];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++) cin>>input[i];
    for(auto c: input){
        int index=0;
        while(c){
            if(c&1){ arr[index]++ ;}
            c>>=1;
            index++;
        }
    }
    unsigned res = 0;
    for (int i = 0; i<32; i++)
        res += (arr[i] % k) * (1 << i);
    cout<<res<<endl;
    return 0;
}