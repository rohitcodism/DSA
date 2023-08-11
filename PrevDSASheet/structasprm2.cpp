//In call by address if the parameter  in the function is modified then the function which is in the main function (actual function) is also gets modified
//In call by address if the structers contains an array then the array gets copied in the formal function 
#include<iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
void fun(struct Rectangle *p){
    p->length = 20;
    cout<<"Length : "<<p->length<<endl<<"Breadth : "<<p->breadth<<endl;//If we use call by address instead of r.length use r->length 
}
int main(){
    struct Rectangle r={10,5};
    fun(&r);
    cout<<"Length is : "<<r.length<<endl<<"Breadth is : "<<r.breadth<<endl;
    return 0;
}