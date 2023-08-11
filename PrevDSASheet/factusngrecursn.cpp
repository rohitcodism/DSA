#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }else{
        return fact(n-1)*n;
    }
}
int main(){
    int r,x;
    cout<<"Enter total numbers"<<endl;
    cin>>x;
    r=fact(x);
    cout<<"The factorial of first "<<x<<" numbers is "<<r<<endl;
}