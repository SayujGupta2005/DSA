#include<bits/stdc++.h>
using namespace std;
int n,W,K;
int w[1001];
int p[1001];
int dp[101][1001][101];
int rec(int i,int wtaken,int ktaken){
    //pruning(Not needed in this problem)
    //basecase(The last item is n-1 )
    if(i==n){
        return 0;
    }
    //cache check
    if(dp[i][wtaken][ktaken]!=-1){
        return dp[i][wtaken][ktaken];
    }
    //recursion
    int ans=rec(i+1,wtaken,ktaken);
    if(wtaken+w[i]<=W && ktaken+1<=K){
        ans=max(ans,p[i]+rec(i+1,wtaken+w[i],ktaken+1));
    }
    //return
    dp[i][wtaken][ktaken] = ans;
    return ans;
}
int main(){
    cin>>n>>W>>K;
    for(int i=0;i<n;i++){
        cin>>p[i]>>w[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans=rec(0,0,0);
    cout<<ans<<endl;
    return 0;
}
//Time Complexity of this code is O(n*W*K)