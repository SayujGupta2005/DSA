#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    } 
};

Node* BinaryTree(Node *root){
    cout<<"Enter the data "<<endl;
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    root=new Node(d);
    cout<<"for left"<<endl;
    root->left=BinaryTree(root->left);
    cout<<"for right "<<endl;
    root->right=BinaryTree(root->right);
    return root;
};

void levelordertraversal(Node *root){
    cout<<endl<<"LevelOrderTraversal: "<<endl;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }}
    }
}
void reverseLevelOrderTraversal(Node* root) {
    cout << endl << "Reverse Level Order Traversal: " << endl;
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        s.push(temp);
    
    if(temp==NULL){
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }
    }

    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();
        if(temp==NULL){
            cout << endl;
        }

        else{cout << temp->data << " ";}
    }
    cout<<endl;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);s
    cout<<root->data<<" ";
}
int main(){
    // Data =1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root=NULL;
    root=BinaryTree(root);
    levelordertraversal(root);
    reverseLevelOrderTraversal(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}
