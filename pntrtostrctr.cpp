#include<iostream>
using namespace std;
struct rect{
int length;
int breadth;
};
int main(){
//normal pointer
  rect r={10,5};
  cout<<r.length<<endl;
  cout<<r.breadth<<endl;

//pointer to strcuture 
//if we use pointer the in "cout" we use "->" instead of "<<"
 struct rect *p=&r;
 p->length=15;
 p->breadth=20;
  cout<<p->length<<endl;
  cout<<p->breadth<<endl;

//pointer to structure with dynamic memory allocation
  struct rect *x;
  x= new rect;
  p->length =20;
  p->breadth = 35;
  cout<<p->length<<endl;
  cout<<p->breadth<<endl; 
  return 0;
}