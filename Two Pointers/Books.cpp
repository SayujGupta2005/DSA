//Sliding Window Approach

#include<bits/stdc++.h>
using namespace std;

int Count(vector<int>v,int n,long long int s){
    int count=0;
    int maxcount=0;
    int sum=0;
    for(int i{0};i<n;i++){
        if(sum+v[i]<=s){
            sum+=v[i];
            count++;
        }
        else{
            sum=sum-v[i-count]+v[i];  /*We slide the window to right by removing the oldest element*/          
        }
        maxcount=max(count,maxcount);
    }
    return maxcount;

}

int main(){
    int n;
    long long int s;
    cin>>n>>s;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<Count(v,n,s);
    return 0;
}
