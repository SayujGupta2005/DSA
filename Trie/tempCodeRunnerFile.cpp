// LuvBabbar_lec-79

//Time Complexity- Insertion= O(l){l=length of word}
//               - Search= O(l){l=length of word}

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){ //constructor
        data=ch;
        for(int i{0};i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }


};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'A'; //Assuming word will be in caps
        TrieNode* child;
        if(root->children[index]!=NULL){
            //present
            child=root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //Recursion 
        insertUtil(child,word.substr(1));
    }
    void insertword(string word){
        insertUtil(root,word);
    }
    bool SearchUtil(TrieNode * root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode* child;
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        return SearchUtil(child,word.substr(1));
    }
    bool search(string word){
        return SearchUtil(root,word);
    }
    void removeUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=false;
            return;
        }
        int index= word[0]-'A';
        TrieNode* child;
        child=root->children[index];
        removeUtil(child,word.substr(1));
    }
    void remove(string word){
        removeUtil(root,word);
    }

};

int main(){
    Trie *t=new Trie();
    t->insertword("SAYUJ");
    cout<<t->search("SAYUJ")<<endl;
    t->remove("SAYUJ");
    cout<<t->search("SAYUJ")<<endl;
    return 0;
}