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
    while(i>1 && z<k+1){
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