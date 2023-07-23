#include<iostream>
using namespace std;
class Rectangle{
private :
int length;
int breadth;
public : 
Rectangle(){
    length = 0;
    breadth = 0;
}
Rectangle(int l,int b){
    length = l;
    breadth = b;
}
int area( int l, int b){
    return l*b;
}
int peremeter(int l, int b){
    int p = 2*(l+b);
    return p;
}
int changelength(int l){
    length = l;
    return l;
}
};
int main(){
    Rectangle r(0,0);
    int l,b,n;
    cout<<"Enter the length : "<<endl;
    cin>>l;
    cout<<"Enter the breadth : "<<endl;
    cin>>b;
    cout<<"Enter the new length of the Rectangle is : "<<endl;
    cin>>n;
    int y = r.area(l,b);
    int x = r.peremeter(l,b);
    int z = r.changelength(n);
    cout<<"The area of the Rectangle is : "<<y<<endl;
    cout<<"The peremeter of the Rectangle is : "<<x<<endl;
    cout<<"The new length of the Rectangle is : "<<z<<endl;
    return 0;
}
