// LuvBabbar_lec-43
 
#include<bits/stdc++.h>
using namespace std;

 // 1) Encapsulation
 // It is the process of enclosing data members and their properties in a common layer
 // So a class is a perfect example of encapsulation

 //2) Inheritance
 // It is the process of inheriting the properties of one class to another class
 //private objects in parent class won't be accessible in child class
 //public onjects in parent class will be accessed according to the access modifier used in child class while inheriting
 //protected objects in parent class will be: Protected if access modifier is public or protected in child class
 //                                         : Private if access modifier is private in child class


//3) MultiLevel Inheritance
// Class Animal is inherited by class Dog and class Dog is inherited by class German Shepherd


//4) Multi-Inheritance
//Inheriting multiple classes at same time

//5) Hybrid Inheritance
//Combination of different types of inheritances like multiple and multilevel inheritance

//6) Inheritance Ambiguity 
//If a class A inherits both class B and C and both classes have same function called func,
// C object
// then there'll be error if we call object.func();
// So we use scope resolution and write as object.B::func(); {If we want to call func of B}


class Humans{

    public:
    int height;
    int weight;
    int age;

    public:
    int getHeight(int height){
        this->height=height;
    }
    int setWeight(int weight){
        this->weight=weight;
    }

};

class Animals{
    public:
    int height;
    int weight;
    
};
class Male:public Humans{

    public:
    string name;
};


class Sayuj: public Male{ // Multi-Level inheritance
    public:
    void printName(){
        cout<<name<<endl;
    };
};

class Experiment: public Humans,public Animals{ //Multi-inheritance
    public:
    string name;
    
};





int main(){
    
    Sayuj smartguy;
    smartguy.name = "Sayuj";
    smartguy.printName();

    return 0;
}

//7) Polymorphism
//Two types: Compile Time Polymorphism , Run Time Polymorphism
