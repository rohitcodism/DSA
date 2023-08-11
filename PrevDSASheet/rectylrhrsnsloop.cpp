#include<iostream>
using namespace std;
double e(double x,double n){
    static double s=1;
    if(n==0){
        return 1;
    }else{
        for(int i=0;i<=n;i++){
            s=((s*(x/n))+1);
        }
        return double(s);
    }
}
int mian(){
    cout<<e(1,10)<<endl;
}