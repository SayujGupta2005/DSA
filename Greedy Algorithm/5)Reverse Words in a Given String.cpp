// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbDhKZW1IMlV2NWtla21HVUhBUEhMeGZsU3J0Z3xBQ3Jtc0tuMmdpQzRIVnlkM1ZSaURVUHJvem1WZWRNQVVmUmRTWmRYTE1wSEpsRklDQTBBVVhidGUtdWZhMDg0alVwVXJMclBvZ0d1c3VyVkoxVW5ENHNHQUp2UXpMM2NyZlJ4b3pLWGMyZWdMSkpPcDdDSnNNdw&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Freverse-words-in-a-given-string5459%2F1&v=HZOUwKCKF5o
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> tot_ans;
        stringstream ss(S);
        char delimiter='.';
        string ans;
        while (getline(ss, ans, delimiter)) { 
        tot_ans.push_back(ans); 
        }
        int n=tot_ans.size();
        string s=tot_ans[n-1];
        for(int i{n-2};i>=0;i--){
            s+='.'+tot_ans[i];
        }
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends