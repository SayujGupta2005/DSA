// FROG 1
/* 

    ATTEMPT 1(Self Method -Wrong)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> heights(n); // Initialize the vector with size n
    int i{0};
    while(i<n){
        cin>>heights[i];
        i++;
    }
    if(n==2){
        cout<<abs(heights[1]-heights[0])<<endl;
    }
    else{
        int z{n-1};
        int cost{0};
        while(z>0){
            int h1=abs(heights[z]-heights[z-1]);
            int h2=abs(heights[z]-heights[z-2]);
            if(h1<h2){
                cost+=h1;
                z--;
            }
            else{
                cost+=h2;
                z-=2;
            } 
        }
        cout<<cost<<endl;
    }
    return 0;
} 
*/


/*
    ATTEMPT 2   
//Brute Force Recursion -Right but Tmie Complexity exponential so TLE

// Logic - It's a top to bottom approach where think of it like a binary tree
            (Further expalanation in notes)
#include<bits/stdc++.h>
using namespace std;

int h[100000];

int rec(int i){
    if(i==0){
        return 0;
    }
    int cost=0;
    cost=rec(i-1) + abs(h[i]-h[i-1]);
    if(i>1){
    cost=min(cost,rec(i-2) +abs(h[i]-h[i-2]));
    }
    return cost;
}

int main(){
    int n;
    cin>>n;
    for(int i{0};i<n;i++){
        cin>>h[i];
    }
    cout<<rec(n-1)<<endl;
    return 0;
}
*/
/*

        ATTEMPT 3
//Dynamic Programming - Correct

#include<bits/stdc++.h>
using namespace std;

int h[100000];
int dp[1000000]; //Here the no of changing variables in each func is one i.e. just 'int i'
                 //so the dp array will be 1-D

int dprec(int i){
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int cost=0;
    cost=dprec(i-1) + abs(h[i]-h[i-1]);
    if(i>1){
    cost=min(cost,dprec(i-2) +abs(h[i]-h[i-2]));
    }
    return dp[i]=cost;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i{0};i<n;i++){
        cin>>h[i];
    }
    cout<<dprec(n-1);
    return 0;
}

*/

//      FROG -2
#include<bits/stdc++.h>
using namespace std;

int h[100000];
int dp[1000000]; //Here the no of changing variables in each func are 2 i.e.  'int i'
                 //so the dp array will be 1-D

int dprec(int i,int k){
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int cost=0;
    cost=dprec(i-1,k) + abs(h[i]-h[i-1]);
    int z=2;
    while(i>=z && z<k+1){
    cost=min(cost,dprec(i-z,k) +abs(h[i]-h[i-z]));
    z++;
    }
    return dp[i]=cost;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    for(int i{0};i<n;i++){
        cin>>h[i];
    }
    cout<<dprec(n-1,k);
    return 0;
}