//LuvBabbar_lec-74

//Heap is a Complete Binary Tree that comes with a Heap Order Property
// Complete Binary Tree -> A binary tree when every level is completely 
//                         filled except last level
//                         The nodes are filled from left to right in each level

// Max heap and Min Heap
// Max Heap -> all child are smaller than their parent node
// Min Heap -> all child are larger than their parent node

// Heap is implemented in form of array

// If a node is at index n, then:
//             it's left node will be at index: 2*n+1
//             it's right node will be at index: 2*n+2
//             it's parent node will be at index: (n-1)/2
//eg= if root node is at index-0,it's left child will be at 1st index 
//                          and it's right child will be at 2nd index 

// Max Heap

#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size=0;
    void insert(int val){
        int index=size;
        arr[index]=val;
        size++;
        while(index>=1){
            int parent=(index-1)/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }  
    }
    void print(){
        for(int i{0};i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    //Whenever we say delete a node, we replace that node with the last element
    //Then we delete it and finally heapify the heap;
    void deleteNode(int i){
        swap(arr[i],arr[size-1]);
        size--;
        while(i<size){
            int left=2*i+1;
            int right=2*i+2;
            if(left<size && arr[i]<arr[left]){
                swap(arr[left],arr[i]);
                i=left;
            }
            else if(right<size && arr[i]<arr[right]){
                swap(arr[right],arr[i]);
                i=right;
            }
            else{
                return;
            }
        }
    }
};

//Heapify = convert an array into a heap
//Heapify is done by comparing the parent and the child and 
// swapping them if the parent is smaller
void Heapify(int arr[],int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        Heapify(arr,largest,n);
    }
    
}
void converttoHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,i,n);
    }
}
void printArray(int hT[],int n){
    for(int i=0;i<n;i++){
        cout<<hT[i]<<" ";}
    cout<<endl;
}

//Heap Sort-
// After converting to Max Heap,the root is the largest element
// And in a sorting algo we know that the largest element is at last
// So we replace the root(largest element) with the last element
// Then we reduce the size of array by 1 and heapify the root so that the second largest element is the root
// Thus we can notice that by repeatedly doing so , we are sorting the array

void Heapsort(int arr[],int size){
    if(size==0){
        return;
    }
    swap(arr[0],arr[size-1]);
    size=size-1;
    Heapify(arr,0,size);
    Heapsort(arr,size);
}

int main(){

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteNode(2);
    h.print();

    int arr[5]{54,53,55,52,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    converttoHeap(arr, n);
    printArray(arr,n);
    Heapsort(arr,n);
    printArray(arr,n);
    return 0;
}