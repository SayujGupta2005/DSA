#include<bits/stdc++.h>
using namespace std;

int n;
int v[101];
bitset<100001> temp;


void func(int y){
    for(int i{0};i<y;i++){
        int x;
        cin>>x;
        temp=temp|temp<<x;
    }
    vector<int>ans;
    for(int i{0};i<100001;i++){
        if(temp[i]){
            ans.push_back(i);
        }
    }
    cout<< ans.size()<<endl;
    for(int i{1};i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    cin>>n;
    temp[0]=1;
    func(n);
    return 0;
}