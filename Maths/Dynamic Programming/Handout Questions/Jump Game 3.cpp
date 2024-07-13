#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>dp(arr.size(),-1);
        return check(arr,start,dp);
    }
private:
    bool check(vector<int>&arr,int x,vector<int> &dp){
        if(arr[x]==0){
            return true;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        dp[x]=0;
        bool ans1=false;
        bool ans2=false;
        if(x-arr[x]>=0){
            ans1=check(arr,x-arr[x],dp);
            }
        if(x+arr[x]<arr.size()){
            ans2=check(arr,x+arr[x],dp);
            }
        if(ans1==true || ans2==true){
            return dp[x]=true;
        }
        return dp[x]=false;
    }
};