#include<bits/stdc++.h>
using namespace std;
int n,s;
int val[101];
long long int dp[1000001];

long long int rec(int sl){
    if(sl==0){
        return 0;
    }
    if(dp[sl]!=-1){
        return dp[sl];
    }
    long long int count=INT_MAX;
    for(int z{0};z<n;z++){
        if(sl>=val[z]){
            count=min(count,rec(sl-val[z])+1);
        }
    }
    return dp[sl]=count;
}

int main(){
    cin>>n>>s;
    for(int i{0};i<n;i++){
        cin>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    long long int ans=rec(s);
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}