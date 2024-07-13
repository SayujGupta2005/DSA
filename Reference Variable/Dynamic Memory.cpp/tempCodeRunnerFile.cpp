#include<bits/stdc++.h>
using namespace std;

int getsum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){

    int n;
    cin>>n;
    int *p=new int[n];

    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    int sum=getsum(p,n);
    cout<<sum<<endl;

    return 0;

}