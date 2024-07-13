#include<bits/stdc++.h>
using namespace std;

int n;
int dp[46];

int rec(int n){
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int count=0;
    count+=rec(n-1);
    count+=rec(n-2);
    return dp[n]=count;
}

int main(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n)<<endl;
    return 0;
}