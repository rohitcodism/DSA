#include<iostream>
using namespace std;
int fun(int n){
    if(n>0){
        cout<<n<<endl;
        return fun(n-1);
    }
    return 0;
}
int main(){
    int a=5;
    cout<<fun(a)<<endl;
}