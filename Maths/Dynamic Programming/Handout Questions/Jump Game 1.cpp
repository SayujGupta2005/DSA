#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return check(nums,0,dp);
    }
private:
    bool check(vector<int>& nums,int x,vector<int> &dp){
        if(x==nums.size()-1){
            return true;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        bool ans= false;
        for(int i=1;i<=nums[x];i++){
            ans=check(nums,x+i,dp);
            if(ans==true){
                break;
            }
        }
        return dp[x]=ans;
    }
};

//This is a leetcode problem so we have to make function only