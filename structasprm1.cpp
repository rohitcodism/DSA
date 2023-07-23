#include<iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
void fun(struct Rectangle r){
    r.length = 47;
    cout<<"length : "<<r.length<<endl<<"breadth : "<<r.breadth<<endl;
}
int main(){
   struct Rectangle r ={10,5};
   fun(r);
   cout<<"Length is : "<<r.length<<endl<<"Breadth is : "<<r.breadth<<endl;
}