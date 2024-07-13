#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
long long int rec(long long int n,vector<long long int> &dp){
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    long long int count{0};
    for(int z{1};z<=6;z++){
        if(n-z>=0){
            count=(count+rec(n-z,dp))%Mod;
        }
    }    
    return dp[n]=count;
}

int main(){
    long long int n;
    cin>>n;
    vector<long long int> dp(n+1,-1);
    // cout<<dp[n]<<endl;
    cout<<rec(n,dp)<<endl;
    return 0;
}