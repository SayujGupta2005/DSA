// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmNIS3ZpUzdfcGxaM3dlSlM2Z2pHZm1MVXdYUXxBQ3Jtc0tsM0FERzhnX01IUzc4ZFgyMG5jMmw1T29Bcy1DZUVHb1F3UlhQXzVlSGxuTGNTQU4xSk1FdHlkMVZPVmwwdmoyVHVCLVJxekM5SEo3N0ZmazJIeUJhWXFMZW9TOHZqLUpVSGdMV2lHTjZWQ0xxU1B3NA&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fshop-in-candy-store1145%2F1&v=HZOUwKCKF5o
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> ans;
        float a=N;
        float b=K+1;
        int n=ceil(a/b);
        sort(candies,candies+N);
        int min=0,max=0;
        for(int i{0};i<n;i++){
            min+=candies[i];
            max+=candies[N-i-1];
        }
        
        ans.push_back(min);
        ans.push_back(max);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends