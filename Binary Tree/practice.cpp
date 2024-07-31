#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
Node* lca(Node *root,int v1,int v2){
    if(root==NULL){
        return NULL;
    }
    if(root->data<v1 && root->data<v2){
        lca(root->right,v1,v2);
    }
    if(root->data>v1 && root->data>v2){
        lca(root->left,v1,v1);
    }
    return root;
}

int height1(Node* root){
    if(root==NULL){
        return 0;
    }
        int a=height1(root->left);
        int b=height1(root->right);
        return max(a+1,b+1);
}
int height(Node *root){
    return height1(root)-1;
}
};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}



Node* lca(Node *root,int v1,int v2){
    if(root==NULL){
        return NULL;
    }
    if(root->data<v1 && root->data<v2){
        lca(root->right,v1,v2);
    }
    if(root->data>v1 && root->data>v2){
        lca(root->left,v1,v1);
    }
    return root;
}

Node* insert(Node*root,int data){
    if(root=NULL){
        return new Node(data);
    }else{
        Node *curr;
    if(data<=root->data){
        curr=insert(root->left,data);
        root->left=curr;
    }
    else{
        curr=insert(root->right,data);
        root->right=curr;
    }}
    return root;
}

