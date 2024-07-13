#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int acount[strs.size()][2];
        for(int i=0;i<strs.size();i++){
            int zero=cntZ(strs[i]);
            int one=strs[i].size()-zero;
            acount[i][0]=zero;
            acount[i][1]=one;
        }
        int dp[101][101][601];
        memset(dp, -1, sizeof(dp));
        return rec(acount,m,n,0,strs.size(),dp);
    }
    
private:
    int cntZ(string s){
        int count=0;
        for(int i{0};i<s.size();i++){
            if (s[i]=='0'){
                count++;
            }
        }
        return count;
    }
    int rec(int acount[][2],int m,int n,int index,int lim,int dp[][101][601]){
        if(index==lim || m+n==0){
            return 0;
        }
        if(dp[m][n][index]!=-1){
            return dp[m][n][index];
        }
        int include=0,exclude=0;
        exclude=rec(acount,m,n,index+1,lim,dp);
        if(m-acount[index][0]>=0 && n-acount[index][1]>=0){
            include=rec(acount,m-acount[index][0],n-acount[index][1],index+1,lim,dp)+1;
        }
        return dp[m][n][index]=max(include,exclude);
    }
};