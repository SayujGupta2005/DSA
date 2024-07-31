//LuvBabbar_lec-78

//Hashmaps = Data structure
// We'll use HashTables which have a Time Complexity of O(1) for insertion/deletion/searching

// Unordered map- Based on hashtable
            // Objects are stored in sorted manner if integers
//Map - Order of objects is preserved   

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


//Bucket array - An array in which we put key,value pairs using Hash Functions

// Hash Functions: consists of 2 parts-
//1)Hash Code - Convert key of a pair into integer index of bucket array
//2)Compression function - Let's say the hash code converts key into integer 16,
//                         but our bucket array is of size 8 (0-7 index),
//                         then we'll use compression function to convert 16
//                         into an integer that can be an index of the array

//Examples of Hash code-
//1) Sum of ascii values of all characters in a string key
//2) (ascii value of 1st char)*0 + (2nd char)*1 + (3rd char)*2......


// **Collision Handling** 
// Preventing 2 strings to have same output of hash code(eg- Sayuj and Suyaj)
// 2 Ways for collision handling:
//      1) Open Hashing / Separate Chaining
//      2) Closed Addressing

//1) Open Hashing/Separate Chaining
//   --- In this,we create a linked list at the index 
//       where two or more keys are colliding

//2) Closed Addressing
//   --- In this, we use H(i)[a]= h[a]+F(i)[a]
//   h[a]=the original index received from hash code
//   F(i)[a]=the function that will be used to find the new index if h[a] is filled
//              { i= no of times h[a] has been repeated}   
//           eg- F(i)[a]=i (linear probing),
//               F(i)[a]=i*i (quadratic probing)
//   H(i)[a]=new index of i'th h[a]

// Let the no of words be 'n' and each word has 'k' letters and no of boxes in an array be 'b'
// Time Comlexity of HashCode= O(1) {although it seems O(k) but if n>>k, then k~constant}
// Time Complexity of Compression Function= O(1)

// We may think that in Seaparte Chaining, if all the words get same hash code,
// then the no of entries in a box will be=n 
// and linked list will be too large to traverse

// But we have a rule i.e. Load Factor=n/b should never be greater than 0.7
// and Load Factor is the no of entries in a box
// So, if we have 1000 words and 1000 boxes, then Load Factor=1 and Time Complecity=O(1)

//ReHashing - Increasing bucket array i.e. 'b' to decrease Load Factor


#include<bits/stdc++.h>
using namespace std;
int main(){

    return 0;
}