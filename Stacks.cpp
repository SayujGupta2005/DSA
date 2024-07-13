// #include<iostream>
// #include<stack>
// using namespace std;
// int main(){
//     stack<int> s;
//     s.push(2);
//     cout<<s.top() <<endl;
//     s.push(3);
//     cout<<s.top();
//     return 0;

// }

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        this->data=val;
        this->next=NULL;
    }
};
class Stack{
    public:
    Node *top;
    Stack(){
        top=NULL;
        }

    void pushf(Node * &top,int data){
        Node *temp=new Node(data);
        if(top==NULL){
            top=temp;
        }
        else{
            temp->next=top;
            top=temp;
        }
    }
    void traverse(Node * top){
        while(top!=NULL){
            cout<<top->data<<" ";
            top=top->next;
        }
        cout<<endl;
    }
};

int main(){
    Stack s;
    Node *top=NULL;
    s.pushf(top,10);
    s.traverse(top);
    s.pushf(top,20);
    s.traverse(top);
    s.pushf(top,30);
    s.traverse(top);

    return 0;
}
