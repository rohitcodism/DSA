#include<iostream>
using namespace std;
int anybasetodecimal(int n,int b){
    int ans=0;
    int power=1;
    while(n!=0){
        int r=n%10;
        n/=10;
        ans+=(r*power);
        power*=b;

    }
    return ans;

}
int main(){
    int n,b;
    cin>>n>>b;
    cout<<anybasetodecimal(n,b)<<endl;
}