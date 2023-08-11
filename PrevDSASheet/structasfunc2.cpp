
#include<iostream>
using namespace std;
struct Rectangle{//We have contained a length and breadth of the rectangle in a box
    int length;
    int breadth;
};
void intialize (struct Rectangle *r,int l, int b)
{
    r->length = l;
    r->breadth = b;
};
int area(Rectangle r){//We have passed the box here.In this line giving struct is not mandatory if it is a c++ program
  int a = r.length*r.breadth;
  return a;
}
int peremeter(struct Rectangle r){//and here also we have passed  the box
    int p = 2*(r.length+r.breadth);
    return p;
}
int main(){
     Rectangle r = {0,0};
     int l,b;
     cout<<"Enter the  length of the rectangle : "<<endl;
     cin>>l;
     cout<<"Enter the breadth of the rectangle : "<<endl;
     cin>>b;
     intialize(&r, l, b);
     int x = area(r);//It can't direactly access the length and breadth directly as it is contained in a box so we have to pass the box 'r' here also
     int y = peremeter(r);//and the same thing here
     cout<<"The area of the Rectangle is : "<<x<<endl;
     cout<<"The peremeter of the Rectangle is : "<<y<<endl;
}