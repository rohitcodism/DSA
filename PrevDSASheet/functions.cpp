#include<iostream>
using namespace std;
int add(int x, int y){
    int z;
    z = x + y;
    return z;
}
int main(){
    int a,b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    cout<<"The sum of "<<a<<" and "<<b<<" is "<<add(a,b)<<endl;
}