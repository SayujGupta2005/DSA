// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbWRHcnMzWkJkU1BfOWItTE9sak4yckw2bzN6UXxBQ3Jtc0ttanlGWjVHM1FyTnMtUkVNd0kzYWE0VWp5aGJ6dEo3NV9sTkFCRGNxS3dwczRfWjVxMUtEZUItTEo4MXhQWlg3M0M3UEMxR2xUeDJab2RGcWpsSE1XTGtrajZMcl8ybHNPbExxckl0MVhybElnRXRURQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fmaximum-meetings-in-one-room%2F1&v=HZOUwKCKF5o
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    static bool comp(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b){
        return a.first.second<b.first.second;
    }

    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int,int>,int>> v;
        for(int i{0};i<N;i++){
            pair<int,int>p1=make_pair(S[i],F[i]);
            pair<pair<int,int>,int>p2=make_pair(p1,i+1);
            v.push_back(p2);
        }
        
        sort(v.begin(),v.end(),comp);
        
        vector<int>ans;
        ans.push_back(v[0].second);
        int ansend=v[0].first.second;
        for(int i{1};i<N;i++){
            if(v[i].first.first>ansend){
                ans.push_back(v[i].second);
                ansend=v[i].first.second;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends