#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    public:
    int size;
    Node *front;
    Node *rear;
    Queue(int val){
        this->size=val;
        front = NULL;
        rear = NULL;
    }
    void en(int data){
        Node *temp = new Node(data);
        if(front == NULL){
            front = temp;
            rear = temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    
    }
    void pop(){
        if(front!=NULL){
            Node *temp=front;
            front=front->next;
            cout<<"Deleting "<<temp->data<<endl;
            delete temp;
        }
    }


};