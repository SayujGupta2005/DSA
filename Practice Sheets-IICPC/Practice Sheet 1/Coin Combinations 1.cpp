#include<bits/stdc++.h>
using namespace std;

int n,s;
int v[101];
long long int dp[1000001];
const int Mod=1e9+7;
long long int rec(int s){
    if(s==0){
        return 1;
    }
    if(dp[s]!=-1){
        return dp[s];
    }
    long long int count{0};
    for(int i=0;i<n;i++){
        if(s>=v[i]){
            count=(count+rec(s-v[i]))%Mod;
        }
    }
    return dp[s]=count;
}

int main(){
    cin>>n>>s;
    for(int i{0};i<n;i++){
        cin>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(s)<<endl;
    return 0;
}