
//Method 1 (Conventional Way == Time Limit Exceeded)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,s;
//     cin>>n>>s;
//     int arr[n];
//     for(int i{0};i<n;i++){
//         cin>>arr[i];
//     }
//     int sum{0};
//     bool check(false);
//     for(int x{0};x<n;x++){
//         sum=arr[x];
//         for(int y{x+1};y<n;y++){
//             sum=sum+arr[y];
//             if(sum==s){
//                 cout<<x+1<<" "<<y+1;
//                 check=true;
//                 break;
//             }
//             else{
//                 sum=arr[x];
//             }

//         }
//         if(check){break;}
//     }
//     if(!check){
//         cout<<"IMPOSSIBLE"<<endl;
//     }
//     return 0;

// }
//Method 2(Two Pointer)
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,s;
    cin>>n>>s;
    long long int arr[n];
    for(int i{0};i<n;i++){
        cin>>arr[i];
    }
    vector<pair<long long int, int>> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back({arr[i], i + 1});
    }
    sort(vec.begin(),vec.end());
    bool check=true;
    int l=0;
    int r=n-1;
    while(l<r){
        long long int sum =vec[l].first+vec[r].first;
        if(sum==s){
            cout<<vec[l].second<<" "<<vec[r].second<<endl;
            check=false;
            break;
        }
        else if(sum<s){
            l++;
        }
        else{
            r--;
        }

    }
    if(check){
        cout<<"IMPOSSIBLE";
    }
    return 0;
}

//Method 3(SETS)
// #include <bits/stdc++.h>
// #define ll long long

// using namespace std;

// void solve(ll* arr, ll N, ll X)
// {
//     map<ll, ll> m1;
//     bool flag = true;
//     for (int i = 0; i < N; i++) {
//         if (flag) {
//             if (m1.find(X - arr[i]) != m1.end()) {
//                 cout << (*(m1.find(X - arr[i]))).second
//                     << " " << i + 1;
//                 flag = false;
//             }
//             m1.insert({ arr[i], i + 1 });
//         }
//     }
//     if (flag)
//         cout << "IMPOSSIBLE";
// }
// int main()
// {
//     ll N = 4, X = 8;
//     ll arr[] = { 2, 7, 5, 1 };
//     solve(arr, N, X);
// }



