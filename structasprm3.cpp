//function(fun) is creating the object in heap and there is a pointer for so it can be accessed by the main function
#include<iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
struct Rectangle *fun(){
    struct Rectangle *p;
    p = new Rectangle;
    p->length = 4;
    p->breadth = 5;
    return p;   
}
int main(){
    struct Rectangle *ptr=fun();
    cout<<"Length : "<<ptr->length<<endl<<"Breadth : "<<ptr->breadth<<endl;
    return 0;
}