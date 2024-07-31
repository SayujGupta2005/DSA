// LuvBabbar_lec-69

//In a BST, a binary tree has it's left node smaller than it's root and right node greater than it's root 

#include<bits/stdc++.h>
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

Node* BinarySearchTree(Node *root,int d){
    if(root == nullptr){
        return new Node(d);
    }
    else{
        Node *insert=nullptr;
        if(d<=root->data){
            insert=BinarySearchTree(root->left,d);
            root->left=insert;
        }
        else{
            insert=BinarySearchTree(root->right,d);
            root->right=insert;
        }
    }
    return root;
};

void levelordertraverse(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right)q.push(temp->right);
            
        }
    }
}
void inorder(Node *root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root==nullptr){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//When implementing Binary Search then use iterative approach due TLE error

void fdelete(Node* root,int data){
    Node *temp= root;
    Node *parent=nullptr;
    
    while(temp!=nullptr){
        if(temp->data==data){
            break;
        }
        else if(temp->data>=data){
            parent=temp;
            temp=temp->left;
        }
        else{
            parent=temp;
            temp=temp->right;
        }
    }
    if (temp == nullptr) {
        return;
    }
    if(temp==root){
        root=nullptr;
    }
    if(parent->left==temp){
        parent->left=nullptr;
        if(temp->left != nullptr && temp->right!=nullptr){
            parent->left=temp->left;
            Node *temp2=temp->left;
            while(temp2->right!=nullptr){
                temp2=temp2->right;
            }
            temp2->right=temp->right;
        }
        else if(temp->left){
            parent->left=temp->left;
        }
        else if(temp->right){
            parent->left=temp->right;
        }
        delete temp;
    }
    else{
        parent->right=nullptr;
        if(temp->left != nullptr && temp->right!=nullptr){
            parent->right=temp->left;
            Node *temp2=temp->left;
            while(temp2->right!=nullptr){
                temp2=temp2->right;
            }
            temp2->right=temp->right;
        }
        else if(temp->left){
            parent->right=temp->left;
        }
        else if(temp->right){
            parent->right=temp->right;
        }
        delete temp;
    }

}

int main(){
    //data = 10 8 21 7 27 5 4 3 -1
    Node *root=nullptr;
    int d=0;
    cin>>d;
    while(d!=-1){
        root=BinarySearchTree(root,d);
        cin>>d;
    }
    levelordertraverse(root);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    fdelete(root,8);
    levelordertraverse(root);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}