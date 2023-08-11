#include<iostream>
using namespace std;
double e(double x,double n){
    static double s=1;
    if(n==0){
        return s;
        }else{
        s=((s*(x/n))+1);
        return double (e(x,n-1));
    }
}
int main(){
    cout<<e(1,10)<<endl;
}