//Making  a class
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
int main(){
    Node* node1=new Node(10);
    cout<<node1->data<<endl<<node1->next;
    
    return 0;
}

//Replacing Node with Lodu
#include<iostream>
using namespace std;

class Lodu{
    public:
    int data;
    Lodu* next;
    
    Lodu(int pussy){
        this->data=pussy;
        this->next=NULL;
    }
};

int main(){
    Lodu* loda1=new Lodu(69);
    cout<<loda1->data<<endl<<loda1->next;
    return 0;
}

//Making a linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
        Node(int val){
            this->data=val;
            this->next=NULL;
        }
        ~Node(){
            int value=this->data;
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
            }
            cout<<"memory freed"<<endl;
        }   
};
    void insertion(Node* &head,Node*& tail,int muthi){
        Node *newNode=new Node(muthi);
        if(tail==NULL && &head==&tail){
        head=newNode;
        tail=newNode;
        newNode->next=NULL;}
        else{
            tail->next=newNode;
            tail=newNode;}
    }
    void  display(Node* head,Node* tail,int n) {
        tail=head;
        int i{0};
          while(i<n-1 && tail!=NULL) {
            tail=tail->next;
            i++;
          }
          if(tail == NULL) {
            cout<<"NULL"<<endl;
            return ;
          }
          cout<<tail->data<<endl;
        
    }
    void traverse(Node*head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    void deleten(Node *&head ,Node *&tail, int position){
        if(position==1){
            Node *temp1=head;
            head=head->next;
            if (head == NULL) {
            tail = NULL; 
            }
            temp1->next=NULL;
            delete temp1;
            return ;
        }
        else{
            Node *temp1=head;
            Node*temp2=NULL;
            head=tail;
            int x=1;
            while(x<position && temp1 != NULL){
                temp2=temp1;
                if (temp1 == tail) {
                tail = temp2;
                }
                temp1=temp1->next;
                x++;;
            }
            if (temp1 == NULL) {
            cout << "Position out of range." << endl;
            return;}
            Node *temp=temp1->next;
            temp2->next=temp;
            temp1->next=NULL;
            delete temp1;
            return ;
        }
    }
        
int main(){
    Node* chota=new Node(420);
    Node* head=chota;
    Node* tail=chota;
    insertion(head,tail,10);
    insertion(head,tail,20);
    insertion(head,tail,30);
    insertion(head,tail,40);
    insertion(head,tail,50);
    traverse(head);
    display(head,tail,5);
    display(head,tail,6);
    display(head,tail,7);
    deleten(head,tail,1);
    traverse(head);
    deleten(head,tail,4);
    traverse(head);
    return 0;
}