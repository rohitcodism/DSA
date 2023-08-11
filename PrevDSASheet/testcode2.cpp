#include<iostream>
using namespace std;
int fun(int n){
    int i=1;
    while(i<=n){
        cout<<i<<endl;
        i++;
    }
    return 0;
}
int main(){
    int a=3;
    cout<<fun(a)<<endl;
}