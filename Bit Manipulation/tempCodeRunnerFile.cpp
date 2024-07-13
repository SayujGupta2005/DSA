#include<bits/stdc++.h>
using namespace std;

bool isOne(int n,int i){
    return (n>>i)&(1);
}

int main(){
    int n,k;
    cin>>n>>k;
    int input[n];
    int arr[32];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++) cin>>input[i];
    for(auto c: input){
        int index=0;
        while(c){
            if(c&1){ arr[index]++ ;}
            c>>=1;
            index++;
        }
    }
    unsigned res = 0;
    for (int i = 0; i<32; i++)
        res += (arr[i] % k) * (1 << i);
    cout<<res<<endl;
    return 0;
}