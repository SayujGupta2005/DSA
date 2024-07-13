#include<bits/stdc++.h>
using namespace std;
 int n;
 long long int W;
 long long int wt[101];
 int val[101];
vector<vector<long long int>>dp(101,vector<long long int>(100001,-1));

long long int rec(int x,int v_l){
    if(v_l==0){
        return 0;
    }
    if(x<0){
        return 1e15;
    }
    if(dp[x][v_l]!=-1){
        return dp[x][v_l];
    }
    long long int ans= rec(x-1,v_l);
    if(v_l-val[x]>=0){
        ans=min(ans,wt[x]+rec(x-1,v_l-val[x]));
    }

    return dp[x][v_l]=ans;

}

int main(){
    cin>>n>>W;
    for(int i{0};i<n;i++){
        cin>>wt[i]>>val[i];
    }
    int max_val=1e5;
    for(int i=max_val;i>=0;i--){
        if(rec(n-1,i)<=W){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}