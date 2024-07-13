// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbUhFSDNUN0Nzci1EZjdsd0J4cU5CbndpMzJNZ3xBQ3Jtc0trazlKQlNyMUZ3UzZhUENZb3VBLUNwOTBqdlJTQ21CaTA0UnRrN0Z3dkdrMUlQdzY4MjNQTmRWbzNXdVU0cUxueTFsczFVUEpZVWt4cWx6WlBxS09abTJOcFJINHRBWFo2V2pPajlpRWVxUUNZR1Y2NA&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Ffractional-knapsack-1587115620%2F1&v=HZOUwKCKF5o
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
  
    static bool comp(pair<double,int> a, pair<double,int> b){
        return a.first>b.first;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        
        vector<pair<double,int>> vw;
        for(int i{0};i<n;i++){
            double W=arr[i].weight;
            double V=arr[i].value;
            pair<double,int> pr=make_pair(V/W,i);
            vw.push_back(pr);
        }
        sort(vw.begin(),vw.end(),comp);
        
        double totalvalue{0};
        
        for(int i{0};i<n;i++){
            int index=vw[i].second;
            if(arr[index].weight<=w){
                totalvalue+=arr[index].value;
                w-=arr[index].weight;
            }
            else{
                totalvalue+=vw[i].first*w;
                break;
            }
        }
        
        return totalvalue;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends