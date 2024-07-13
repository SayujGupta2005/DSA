#include<bits/stdc++.h>
using namespace std;

long long int n,w;
long long int wt[101],v[101];
vector<vector<long long int>> dp( 101 ,vector<long long int>(100001,-1));

long long int knapsack(int x,long long int w){
    if(x==0||w==0){
        return 0;
    }
    if(dp[x][w]!=-1){
        return dp[x][w];
    }
    long long int capacity=0;
    if(w-wt[x-1]>=0){
        capacity=max(knapsack(x-1,w),v[x-1]+knapsack(x-1,w-wt[x-1]));
    }
    else{
        capacity=knapsack(x-1,w);
    }
    return dp[x][w]=capacity;

}


int main(){
    cin>>n>>w;
    for(int i{0};i<n;i++){
        cin>>wt[i]>>v[i];
    }
    cout<<knapsack(n,w)<<endl;
    return 0;
}