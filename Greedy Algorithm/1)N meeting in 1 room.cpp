//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmNtTXBxNEtGVExaRG5ON1liWmpkOWpxckJjZ3xBQ3Jtc0tudzRod1NXY0UxSkxKQXp3NEFVXzllZUJPOFBBTmVxV3lyaXFpWVFSNWozb05tZ1dLOFhud05lLVA3NHRuVEFIREQ4b3R4LTd6RFhMVmg0WmM5SXo1MHJpRy1qN2sxdzNpN2NDZWZsUUtRV21GVDZNdw&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fn-meetings-in-one-room-1587115620%2F1&v=HZOUwKCKF5o

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        vector<pair<int,int>> v;
        for(int i{0};i<n;i++){
            pair<int,int> p=make_pair(start[i],end[i]);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),comp);
        
        int count =1;
        int ansend=v[0].second;
        for(int i{1};i<n;i++){
            if(v[i].first>ansend){
                count++;
                ansend=v[i].second;
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends