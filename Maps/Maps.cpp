// MAPS (Unordered maps mei bas unsorted hote hain)
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string> m;
    m[1]="one";
    m[2]="two";
    m[3]="three";
    cout<<m[2]<<endl;
    
    m.insert({4,"four"});
    
    cout<<m[4]<<endl;
    
    for(auto &pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }

    auto it =m.find(3);
    if(it==m.end()){
        cout<<"No Value";
    }
    else{
        cout<<it->first<<" "<<it->second<<endl;
    }
    
    m.erase(3);//Index 3 has been deleted
    for(auto &pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    

    return 0;
}
