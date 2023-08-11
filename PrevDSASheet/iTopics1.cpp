#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main(){
    int x, y;
    cout<<"enter the first value : "<<endl;
    cin>>x;
    cout<<"Enter the second value : "<<endl;
    cin>>y;
    cout<<"The first value is : "<<x<<". The second value is : "<<y<<"."<<endl;
    swap(x,y);
    cout<<"After swapping the first variable is : "<<x<<". The second variable is : "<<y<<"."<<endl;
}