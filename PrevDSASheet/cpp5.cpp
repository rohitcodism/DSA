#include<iostream>
using namespace std;
int decimaltoanybase(int n,int b){
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
        int n,b;
        cin>>n>>b;
        cout<<decimaltoanybase(n,b)<<endl;


    }
