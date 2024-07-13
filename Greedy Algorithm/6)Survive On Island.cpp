// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmNhSEp0czNWb01kc2pNMHN3Zkg2Y0pzQkM5UXxBQ3Jtc0tuN1JzQ3hHMlBlSTE2TG83V0EwQUNESmd1eEdfdUhfY1VJamRqRkNMc01yTDZDdlFKMWQwb1NYQUVHQVc2TS1TRzJmcG1qek5KVFZXbU9MV09uMzh2eDBPbFFIZzBCZElKZjhEVVJVaDJzQVdKYVRISQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fcheck-if-it-is-possible-to-survive-on-island4922%2F1&v=HZOUwKCKF5o
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        if(M>N || (M==N && S>=7) || (M * 7 > N * 6 && S > 6)){
            return -1;
        }
        int count{0};
        
        float a=S*M;
        float b=N;
        
        count=ceil(a/b);
        
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends