/* for an empty class 1 byte of memory is allocated */
/*there  are three types of access modifier : 1. public 2. private(by default) 3. protected*/
/*for a private access modifiers we use get and set function to access it or manupulate it. */
/*when we create an object everytime constructor is called, this is called deafault constructor . It has no parameters and no return value. */
/*when we write our own constructor the default constructor gets removed by the program itself*/
/* parameterised constructor : this type of constructor needs input value wheather it is from class call or from default constructor */
#include<iostream>
#include<string.h>
using namespace std;
class hero{
    //class members
    private:
    int health;
    int level;
    public:
    char *name;
    hero(){ 
    health = 100;
    level = 10;
    }
    hero(){
        cout<<"simple constructor called."<<endl;
        name = new char[100];
    }

    hero(int health, int level){
        cout<<"this-> "<<this<<endl;
        cout<<"parameterised constructor is called"<<endl;
        this->health = health;
        this->level = level;
    }
    /*copy constructor*/
    hero(hero& temp){
        cout<<"copy constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    /*print function*/
    void print(){
        cout<<endl;
        cout<<"Name : "<<this->name<<endl;
        cout<<"Health : "<<this->health<<endl;
        cout<<"Level : "<<this->level<<endl;
    }
    int gethealth(){
        return health;
    }
    int getlevel(){
        return level;
    }
    void sethealth(int h){
        health = h;
    }
    void setlevel(int l){
        level = l;
    }
    void setname(char name[]){
        strcpy(this->name, name);
    }
};
int main(){
    // hero ramesh;
    // ramesh.level = 8;
    // //cout<<"size : "<<sizeof(ramesh)<<endl;
    // // cout<<"health is: "<<ramesh.health<<endl;
    // cout<<"level is :"<<ramesh.level<<endl;
    // cout<<"health is: "<<ramesh.gethealth()<<endl;
    // ramesh.sethealth(100);
    //     hero *h = new hero;
    //     h->sethealth(100);
    //     h->setlevel(12);
    //     cout<<"level is : "<<h->level<<"  health is : "<<h->gethealth()<<endl;

    /*object created dynamically*/
    // cout<<"hi"<<endl;
    // hero *h1 = new hero;
    // hero h1;
//     hero ramesh(10,5);
//     ramesh.print();
//     hero ritesh(ramesh);
//     ritesh.print();
    hero hero1;
    hero1.sethealth(120);
    hero1.setlevel(12);
    char name[7] = "Rohit";
    hero1.setname(name);
    hero1.print();
}