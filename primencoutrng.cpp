#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    for(int n=a;n<=b;n++){
        int j;
        for( j=2;j<n;j++){
       if(n%j==0){
        break;
       } 

        }
        if(j==n){
            cout<<n<<endl;
        } 
         
    }
    return 0;
}