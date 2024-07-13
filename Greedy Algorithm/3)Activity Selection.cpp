// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbWRKNWpvMjZZZkhXcl9rWVQtb0lBdkN5NEN3UXxBQ3Jtc0trNFR5eUsyUFo5WHNPT0gzVXNXZjd5T3ZCNWJmS19JcGRMTXQwX0M3UVdlOFZ2VUxfajNjaTlwcjJXV2tKcEdjNEU1RWoza0Y5X19id25LQWJVT2N6ektpMWE4Z21UWGZvOUdjdXptTS10N05fZm5rWQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Factivity-selection-1587115620%2F1&v=HZOUwKCKF5o


 //     Same as Question 1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
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
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code EndsS