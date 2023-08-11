#include<iostream>
using namespace std;
int main(){ 
    int n;
    cout<<"Enter the size"<<endl;
    cin>>n;
    int A[n];
    A[0]=2;
    for( int x:A){
        cout<<x*2<<endl;
    }
}