// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbk4ybWlRcTdDVDJIRDNSX19zVC1ZejRTWjVSZ3xBQ3Jtc0ttcDFPUkdFWkdFVS01NnNEWDZNbl9HREZRUHNFQ1YyOExlVS1Uc3BHaW54eXpLMHk0V3VETEFuVHBtSzQzMlpqMUlKNlQ2TkI2ZmRFdnZKYVhHSDVRSGlraXE3Rms0S21uLW8tZjI4UUMzVzBjQVhuVQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fhuffman-encoding3345%2F1&v=HZOUwKCKF5o
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
class comp{
    public:
    bool operator()(Node *a,Node *b){
        return a->data>b->data;
    }
};


class Solution
{
	public:
	    void traverse(Node* root,vector<string>&ans,string temp){
	        if(root->left==NULL&&root->right==NULL){
	            ans.push_back(temp);
	            return;
	        }
	        traverse(root->left,ans,temp+'0');
	        traverse(root->right,ans,temp+'1');
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node *,vector<Node*>,comp>pq;
		    for(int i{0};i<N;i++){
		        Node* temp=new Node(f[i]);
		        pq.push(temp);
		    }
		    while(pq.size()>1){
		        Node*left=pq.top();
		        pq.pop();
		        Node*right=pq.top();
		        pq.pop();
		        
		        Node *newNode= new Node(left->data+right->data);
		        newNode->left=left;
		        newNode->right=right;
		        pq.push(newNode);
		        }
		        
		    Node* root=pq.top();
		    vector<string>ans;
		    string temp="";
            traverse(root,ans,temp);
	        return ans;
		    
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends