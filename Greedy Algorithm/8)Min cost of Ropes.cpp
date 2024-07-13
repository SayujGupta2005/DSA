// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbU1aa19jNENvNUo1cy1LeEZZdjhQMXpkLWtyUXxBQ3Jtc0tsWU12X1lJQ2pwTkVydDIwdVlpYzNGYTFMR2cxcm5ETjNjY0J0d1JSYjZVSG52RVk2YkpLT1hWR3o4d0pCQUJSTHhxYktVWlJ1Z09ScGpEYkJaRlc2M2ExbmtLZVU0b1dLNEhHaFNvYTBTVlRVYlR6VQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fminimum-cost-of-ropes-1587115620%2F1&v=HZOUwKCKF5o

// PRIORITY QUEUE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater <long long>>pq;
        long long int totalcost=0;
        for(int i{0};i<n;i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            long long int a=pq.top();
            pq.pop();
            long long int b=pq.top();
            pq.pop();
            long long int cost=a+b;
            
            totalcost+=cost;
            
            pq.push(cost);
            
        }
        return totalcost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends