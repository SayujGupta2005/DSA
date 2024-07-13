#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size()-1;
        vector<vector<long long int>>dp(21,vector<long long int>(4001,-1)); //We have taken 4001 bcoz we can add atmost -sum(nums)=-1000 or +sum(nums)=1000
                                                                            // and the target is from -1000 to 1000 so our total range becomes -2000 to 2000
        return Ans(nums,target,n,dp);
        
    }
private:
    long long int Ans(vector<int>& nums, int target,int x,vector<vector<long long int>>&dp){
        if(x<0){
            if(target==0){
            return 1;}
            else{
                return 0;
            }
        }
        if(target>=0){
        if(dp[x][target]!=-1){
            return dp[x][target];
        }}
        else if(target<0){
            if(dp[x][2000-target]!=-1){
            return dp[x][2000-target];
        }}
        long long int count=0;
        count+=Ans(nums,target-nums[x],x-1,dp) +Ans(nums,target+nums[x],x-1,dp);
        if(target>=0){
            return dp[x][target]=count;
            }
        else{
            return dp[x][2000-target]=count;
        }
    }
};