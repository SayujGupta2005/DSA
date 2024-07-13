#include<bits/stdc++.h>
using namespace std;

class Hero2{
    private:
    char *name;
    int health;
    int level;
    
    public:
    int power;


    Hero2(){
        cout<<"Constructor has been called"<<endl;
    }

    ~Hero2(){
        cout<<"Destructor has been called"<<endl;
    }



};

int main(){

    Hero2 p;

    Hero2 *q=new Hero2;


    return 0;
}