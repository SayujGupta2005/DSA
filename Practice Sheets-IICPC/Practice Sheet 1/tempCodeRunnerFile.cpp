#include<bits/stdc++.h>
using namespace std;
 int n;
 long long int W;
 long long int wt[101];
 int val[101];
 vector<long long int>dp(100001,0);

long long int rec(int x){
    
    for(int i{0};i<x;i++){
        for(int j=1;j<=val[i];j++){
            if(j-val[i]>=0){
                dp[j]+=wt[i]+dp[j-val[i]];
                }
        }
    }
    return dp[x];

}

int main(){
    cin>>n>>W;
    for(int i{0};i<n;i++){
        cin>>wt[i]>>val[i];
    }
    long long int w_t=0;
    cout<<rec(n)<<endl;
    return 0;
}