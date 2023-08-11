#include<iostream>
using namespace std;
int factorial(int x){
    int xf=1;
    for(int i=1;i<=x;i++){
        xf*=i;
    }
    return xf;
}
int main(){
    int n,r;
    cin>>n>>r;
    int nf = factorial(n);
    int rf = factorial (r);
    int nmrf = factorial(n-r);
    int ans = nf/(rf*nmrf);
    cout<<ans<<endl;
}