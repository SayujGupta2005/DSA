#include<bits/stdc++.h>
using namespace std;

int n,s;
int v[101];
long long int dp[1000001];
const int Mod=1e9+7;

long long int re(int x){
    for(int i=0;i<n;i++){
        for(int j{1};j<=x;j++){
            if(j-v[i]>=0){
                dp[j]=(dp[j]+dp[j-v[i]])%Mod;
            }
        }
    }
    return dp[x];
}

int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    cout<<re(s)<<endl;
    return 0;
}