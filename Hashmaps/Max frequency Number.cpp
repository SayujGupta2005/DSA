// https://www.naukri.com/code360/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> m;
    for(int i{0};i<n;i++){
        m[arr[i]]++;
    }
    int max=-1;
    int ans;
    unordered_map<int,int>:: iterator it=m.begin();
    while(it!=m.end()){
        if (it->second>max){
            max=it->second;
        }
        it++;
    }
    for(int i{0};i<n;i++){
       if(max== m[arr[i]]){
           ans=arr[i];
           break;
       };
    }
    return ans;
}
