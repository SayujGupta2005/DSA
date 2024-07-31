//LuvBabbar_lec-74

//Priority Queue = Max Heap
//Priority Queue has largest element at top

// To convert priority queue from max heap to min heap,
// first create a priority queue and then put all the elements in stack
// Stack will become Min heap
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;
    
    pq.push(2);
    pq.push(10);
    pq.push(4);
    pq.push(5);
    cout<<"Size of queue is: "<<pq.size()<<endl;
    cout<<"Largest element at top is: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Now the second largest element is: "<<pq.top()<<endl;
    
    
    return 0;
}