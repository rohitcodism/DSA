#include<iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x,y;
    cout<<"Enter any two no.s : ";
    cin>>x>>y;
    swap(&x, &y);
    cout<<x<<y<<endl;
}