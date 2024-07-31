//LuvBabbar_lec-78

//Hashmaps = Data structure
// We'll use HashTables which have a Time Complexity of O(1) for insertion/deletion/searching

// Unordered map- Based on hashtable

#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<string,int> um;
    //Insertion
    pair<string,int>p=make_pair("Sayuj",1);
    um.insert(p);

    pair<string,int> p2("Gupta",33);
    um.insert(p2);

    um["Awesome"]=44;
    um["Awesome"]=11; // If we use the same key then replacement takes place

    //Search
    cout<<um["Sayuj"]<<endl;
    cout<<um.at("Gupta")<<endl;

// If we cout<<um.at("Nice"),we'll get an error bcoz no key "Nice" exists,
// but of we use cout<<um["Nice"], 
// then an entry will be created and it's value will be 0
// Then if we use cout<<um.at("Nice"),we'll get 0 as answer
   // cout<<um.at("Nice")<<endl;
    cout<<um["Nice"]<<endl;
    cout<<um.at("Nice")<<endl;

    //Size
    cout<<um.size()<<endl;

    //To check presence
    cout<<um.count("Sayuj")<<endl;

    //Erase
    um.erase("Awesome");

    //Iterator
    unordered_map<string,int>::iterator it=um.begin();
    while(it!=um.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}