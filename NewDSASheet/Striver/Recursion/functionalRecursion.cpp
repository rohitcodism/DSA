#include<bits/stdc++.h>
using namespace std;


int functionalRecursion(int n){
    if(n == 0)
        return 0;
    return n+functionalRecursion(n-1);
}

int factos(int n){ // using functional recursion
    if(n == 0)
        return 1;
    return n * factos(n-1);
}

void factos2(int n, int fact){ // using parameterized recursion
    if(n == 0){
        cout<<fact<<endl;
        return;
    }
    factos2(n-1,n*fact);
}

int main(){
    cout<<functionalRecursion(6)<<endl;

    cout<<factos(4)<<endl;

    factos2(5,1);

    return 0;
}