// LuvBabbar_lec-42

// Classes and Objects

//Class -> user-defined data type


#include<bits/stdc++.h>
using namespace std;

class Hero{
    // If public not mentioned,then automatically private
private:
    char name[100];
    int health;
public:
    int power;
    void print(){
        cout<<power<<endl;
    }
    int getHealth(){        //This is a Getter
        return health;
    }
    void setHealth(int h){  //This is a Setter
        health = h;
    }


};
//If class is empty then it will have a size of 1 byte, only for identification 
int main(){

    Hero h1;
    cout<<sizeof(h1)<<endl; // Total is 108 (sizeof char = 1byte,sizeof int = 4byte )
                            // So 100*1+4+4=108              
 

    // h1.health=100; Cant't access it due to public
    h1.power=10;
    h1.setHealth(100);
    cout<<h1.getHealth()<<endl;
    //Dynamically
    Hero *h2=new Hero;
    (*h2).setHealth(10000);
    cout<<(*h2).getHealth()<<endl;

    //We can also use:
    // cout<<h1->getHealth()<<endl; Not to h1 bcoz h1 is in static memory
    cout<<h2->getHealth()<<endl;

    return 0;
}

// Constructors
//Whenever we create an object, a constructor is called
//It has no return type
//It has no input parameter



#include<bits/stdc++.h>
using namespace std;

class Villain{
    private:
    char *name;
    int health;
    int level;
    
    public:
    int power;

    Villain(){
        cout<<"Constructor has been called"<<endl;
    }
    //Parameterized Constructor
    Villain(int health,int level){
        cout<<"Parameterized Constructor has been called"<<endl;
        //We want that the health int line 64 should be equal to health in the input here
        //health = health // this command wont work bcoz both health are of same scope

        //So we'll use 'this->' {'this->' is a keyword that points to the attribute of the constructor class
        //                                 So, this->health is equal to the health of line 64 and 
        //                                 is equal to the input parameter of constructor} 
        this->level =level;
        this->health=health; 
    }
    //Deep Copy Constructor
    Villain(Villain &v){
        //To copy name,we'll create a new array
        char *ch=new char[strlen(v.name)+1];
        strcpy(ch,v.name);
        this->name=ch;

        cout<<"Copy Constructor has been called"<<endl;
        this->level = v.level;
        this->health = v.health;
    }
    void print(){
        cout<<"Health is "<<this->health<<endl;
        cout<<"Level is "<<this->level<<endl;
    }
    void setName(char Name[]){
        strcpy(this->name,Name);
    }

    void getHealth(){
        cout<<"Health is "<<this->health<<endl;
    }
    void setHealth(int n){
        health=n;
    }
    void setLevel(int n){
        level=n;
    }
    void getLevel(){
        cout<<"Level is "<<this->level<<endl;
    }

};

int main(){
//Whenever I call Villain v1, something  like v1.Villain() will execute in background
//But we haven't created a function Villain in our class
//This is bcoz when we create a class, a constructor is created by default and has the name os a class
//We can make a constructor ourselves too but then the system default constructor is deleted
    char name[6]="Sayuj";


    Villain v1(100,10); // We can see that v1.Villain() has been called
    v1.setName(name);
    Villain *v2=new Villain;//Even dynamically,teh constructor will be called

//Copy Constructor
    Villain v3(v1); //Right now we are using default copy constructor
                    //Default copy constructor uses shallow copy = any changes made to 
                    //                                             original will change the
                    //                                              copied too...       
                    //But we can create our own too
    v3.print(); 
    return 0;
}

//Shallow copy = Variables are different but memory accessed is same


//Destructor
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
    //Static - Destructor is called automatically
    Hero2 p;
    //Dynamic - Manually call destructor
    Hero2 *q=new Hero2;
    delete q;

    return 0;
}