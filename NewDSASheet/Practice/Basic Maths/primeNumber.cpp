#include<bits/stdc++.h>
using namespace std;

bool primeNum(int n){
    int flag = 0;

    for(int i = 2; i*i < n;i++){
        if(n%i == 0){
            flag++;
            if((n/i) != i)
                flag++;
        }
    }
    if(!flag)
        return true;
    return false;
}

int main(){

    int num;

    cout<<"Enter a number : ";
    cin>>num;
    cout<<endl;

    if(primeNum(num))
        cout<<"The number is prime"<<endl;
    else
        cout<<"The number is not prime"<<endl;

    return 0;
}