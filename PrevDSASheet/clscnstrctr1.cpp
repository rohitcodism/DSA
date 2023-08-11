#include<iostream>
using namespace std;
class Rectangle {
    private :
    int length;
    int breadth;
    public : 
    Rectangle(int l,int b){
        length = l;
        breadth = b;
    }
    int area(){
        return length * breadth;
    }
    int changelength(int l){
        length = l;
        return length;
    }
};
int main(){
    Rectangle r(10,5);
 int y = r.area();
 int x = r.changelength(20);
    cout<< y << endl;
    cout<< x << endl;
}