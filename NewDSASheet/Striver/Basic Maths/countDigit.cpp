#include<bits/stdc++.h>
using namespace std;

void countDigit(int n){
    cout<<"The digits are : "<<endl;
    if(n == 0){
        cout<<0<<endl;
        cout<<"The number of digits is : "<<0<<endl;
        return;
    }
    int flag = 0;
    while(n != 0){
        cout<<n%10<<endl;
        n = n/10;
        flag++;
    }
    cout<<"The number of digits is : "<<flag<<endl;
}

int main(){
    countDigit(7896);
    return 0;
}