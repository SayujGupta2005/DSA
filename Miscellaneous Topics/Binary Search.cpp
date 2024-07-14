#include<bits/stdc++.h>
using namespace std;


//binary search sorted array par lagta hai
int bs(int l,int r,int s,vector<int>&v){
    if(l>=r){
        return 0;
    }
    if(s=v[(l+r)/2]){
        return (l+r)/2;
    }
    else if(s>v[(l+r)/2]){
        return bs((l+r)/2+1,r,s,v);
    }
    else{
        
        return bs(l,l+r/2,s,v);
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i{0};i<n;i++){
        cin>>v[i];
    }
    int s;
    cin>>s;
    cout<<v.size()<<endl;
    cout<<bs(0,v.size()-1,s,v)+1<<endl;
    return 0;
}

//Check Lower Bound and Upper Bound

#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>&v,int element){
    int lo=0,hi=v.size()-1;
    int mid;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(v[mid]<element){ //For upper bound,we'll do v[mid]<=element
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    if(v[lo]>=element){//for upper bound,we'll remove =
        return lo;
    }
    if(v[hi]>=element){//for upper bound,we'll remove =
        return hi;
    }
    return -1;
}

int upper_bound(vector<int>&v,int element){
    int lo=0,hi=v.size()-1;
    int mid;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(v[mid]<=element){ 
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    if(v[lo]>element){
        return lo;
    }
    if(v[hi]>element){
        return hi;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n); //Array should be sorted
    for(int i{0};i<n;i++){
        cin>>v[i];
    }
    int element;
    cin>>element;
    int lb=lower_bound(v,element);
    cout<<lb<<" "<<(lb!= -1 ? v[lb]:-1)<<endl;
    int ub=upper_bound(v,element);
    cout<<ub<<" "<<(ub!= -1 ? v[ub]:-1)<<endl;
}


//Finding Square Root using Binary Search Tree
#include<bits/stdc++.h>
using namespace std;
//if we have to find the sqrt of 16 and we are given a vector from 0 to 16
//Then we'll take mid no ie 8 and see if 8*8 is > or < 16
//As it is >16 so we'll make our high=8 and then take mid of 0 and 8 ie 4
// 4*4==16 so 4 is the sqrt of 16
int eps =1e-1;
int func(int n){
    int lo=0,hi=n;
    while(hi-lo>eps){
        int mid=(lo+hi)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid>n){
            hi=mid;

        }
        else{
            lo=mid;
        }
    }
    return -1;
}

int main(){
    int element;
    cin>>element;
    cout<<func(element)<<endl;
    return 0;
}
