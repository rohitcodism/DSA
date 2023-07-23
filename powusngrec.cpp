#include<iostream>
using namespace std;
int pow(int m,int n){
    if(n==0){
        return 1;
    }else if (n%2==0){
       return pow(m*m,(n/2));
    }else if (n%2!=0){
        return m*pow(m*m,(n/2));
    }
        }

int main(){
    int r,x,y;
    cout<<"Enter the number"<<endl;
    cin>>x;
    cout<<"Enter the power"<<endl;
    cin>>y;
    r=pow(x,y);
    cout<<"The result is "<<r<<endl;
    return 0;
}