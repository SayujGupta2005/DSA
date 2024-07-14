#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        this->data=val;
        this->next=NULL;
        this->prev=NULL;    
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<" Memory freed "<< val<<endl;
    }
};

void insertion(Node* &head,Node *&tail,int value){
    Node *newNode= new Node(value);
    if(tail==NULL){
        head=newNode;
        (head)->prev=NULL;
        tail=head;
        return ;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
} 

void traverse(Node *head,Node *tail){
    Node  *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void display(Node *head,Node * tail,int n){
    Node  *temp = head;
    while(n-- && temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void remove(Node* head,Node *tail,int pos){
    Node *temp1=head;
    int x{1};
    while(x<pos-1){
        temp1=temp1->next;
        x++;
    }
    Node *temp2=temp1->next;
    temp1->next=temp2->next;
    temp2->next->prev=temp1;
    temp2->next=NULL;
    temp2->prev=NULL;
    delete temp2;
}

void rtraverse(Node*head,Node*tail){
    Node *temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}

int main(){
    Node *chota=new Node(5);
    Node *head=chota;
    Node *tail=chota;
    insertion(head,tail,10);
    insertion(head,tail,11);
    insertion(head,tail,12);
    insertion(head,tail,13);
    insertion(head,tail,14);
    insertion(head,tail,15);
    insertion(head,tail,16);
    insertion(head,tail,17);
    traverse(head,tail);
    remove(head,tail,5);
    traverse(head,tail);
    rtraverse(head,tail);
    remove(head,tail,8);
    traverse(head,tail);
    rtraverse(head,tail);
    return 0;
}