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
int decimaltoanybase(int n, int b){
     int ans=0;
    int power=1;
    while(n!=0){
        int r=n%b;
        n/=b;
        ans+=(r*power);
        power*=10;
    }
    return ans;

    }


int main(){
    int n,b1,b2;
    cin>>n>>b1>>b2;
    int decno= anybasetodecimal(n,b1);
    int ans= decimaltoanybase(decno,b2);
    cout<<ans<<endl;
}