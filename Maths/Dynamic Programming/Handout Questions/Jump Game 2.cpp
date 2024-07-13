#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return fcount(nums, 0, dp);
    }

private:
    int fcount(vector<int>& nums, int x, vector<int>& dp) {
        if (x >= nums.size() - 1) {
            return 0;
        }
        if (dp[x] != -1) {
        }
        int count = INT_MAX;
        for (int i = 1; i <= nums[x]; i++) {
            if (x + i <= nums.size()-1) {
                int jumps = fcount(nums, x + i, dp);
                if (jumps != INT_MAX) {
                    count = min(count, jumps + 1);
                }
            }
        }
        return dp[x] = count;
    }
};