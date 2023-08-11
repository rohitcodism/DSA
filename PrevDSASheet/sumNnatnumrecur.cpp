#include<iostream>
using namespace std;
int sum(int n){
    if(n==0){
        return 0;
    }else{
        return sum(n-1)+n;
    }
}
int main(){
    int r,x;
    cout<<"Enter total numbers"<<endl;
    cin>>x;
    r=sum(x);
    cout<<"The sum of first "<<x<<" numbers is "<<r<<endl;
    return 0;
}