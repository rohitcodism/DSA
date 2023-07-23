#include<iostream>
using namespace std;
int fib(int n){
    int t=0,u=1,s;
    if(n<=1)
        return n;
        for(int i=2;i<=n;i++){
            s=t+u;
            t=u;
            u=s;
        }
        return s;
    }

int main(){
    cout<<fib(10)<<endl;
}