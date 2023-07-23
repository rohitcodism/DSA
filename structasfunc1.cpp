#include<iostream>
using namespace std;
struct Rectangle {
    int length;
    int breadth;
};
void intialize(struct Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}
int area(struct Rectangle r){
    int a = r.length * r.breadth ;
    return a;
}
int changelength(struct Rectangle *r, int l){
    r->length = 20;
    return  l;
}
int main(){
    struct Rectangle r;
  intialize(&r, 10, 5);
  int y=  area(r);
  int x= changelength(&r , 20);
    cout<< x << endl<< y << endl;
}