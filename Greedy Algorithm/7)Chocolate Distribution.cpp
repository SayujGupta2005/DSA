// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVRWbjd3Q1JFMGNKNlVJSklZSy1qQzBQblNlQXxBQ3Jtc0trWEtkRjhUZ2hnYlJNbjk2a3MyTnRqeXRhOHpHMk5VdFF1WG5RYUt5Q3NHQjB3MjVEUWlZM1dlV2stQVMxM193MVJfLThZb1FZVUl1N19SZ2t6WGJIaGlKcE1ISHVJSURLNTRJdnFkb0NjMzY1bDZtMA&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fchocolate-distribution-problem3825%2F1&v=HZOUwKCKF5o
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    int min=INT_MAX;
    for(int i{0};i<=n-m;i++){
        if((a[i+m-1]-a[i])<min){
            min=a[i+m-1]-a[i];
        }
    }
        return min;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends