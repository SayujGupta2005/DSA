// LuvBabbar_lec-43
 
#include<bits/std++.h>
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


class Humans{

    public:
    int height;
    int weight;
    int age;

    public:
    int getHealth(int health){
        this->health=health;
    }
    int setWeight(int weight){
        this->weight=weight;
    }

};

class Male:public Humans{

    public:
    string name;


};