// #include<bits/stdc++.h>
// using namespace std;

// int dp[10001][10001];
// int rec(int W, int wt[], int val[], int n) {
//     if (n == 0 || W == 0){
//      return 0;
//     }
//     if (dp[n][W] != -1){
//      return dp[n][W];
//     }
//     int exclude{0},include{0};

//     if (wt[n-1] <= W){
//      int include=val[n-1]+ rec(W-wt[n-1],wt,val,n-1);
//      int exclude=rec(W,wt,val,n-1); 
//     }
//     return max(include,exclude);
// }

// int main() {
//     int n,W,wt[n],v[n] ;
//     cin>>n>>W;
//     for(int i{0};i<n;i++){
//         cin>>wt[i]>>v[i];
//     }
//     memset(dp,-1,sizeof(dp));
//     cout << "Maximum value: " << rec(W, wt, v, n) << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
long long int rec(long long int W, int wt[], int val[],int n, vector<vector<long long int >>&dp) {
    if (n == 0 || W == 0){
        return 0;
    }
    if (dp[n][W] != -1){
        return dp[n][W];
    }
    long long exclude = rec(W, wt, val, n - 1,dp);
    long long int include = 0;
    if (wt[n-1] <= W){
        include = val[n-1] + rec(W - wt[n-1], wt, val, n - 1,dp);
    }
        return dp[n][W] = max(include, exclude);
}

int main() {
    
    int n;
    long long int W;
    cin >> n>> W;
    vector<vector<long long int >>dp(n+1,vector<long long int>(W+1,-1));
    int wt[n], v[n];
    for (int i = 0; i < n; i++){
        cin >> wt[i] >> v[i];
    }
    cout << rec(W, wt, v, n, dp) << endl;

    return 0;
}
