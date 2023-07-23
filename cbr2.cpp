#include<iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRefVar(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x,y;
    cout<<"Enter any two no.s : ";
    cin>>x>>y;
    swapRefVar(x, y);
    cout<<x<<y<<endl;
}