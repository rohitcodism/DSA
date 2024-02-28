#include<bits/stdc++.h>
using namespace std;

void printAllDivisors(int n){
    

    for(int i = 1; i<=n/2;i++){ //** --> +if 36 = 1*36 then 1 and 36 both are factors or divisors of 36 so that's why it is n/2 instead of n in the for loop.
        if(n%i == 0)
            cout<<"The divisor is : "<<i<<endl;
    }
}

int main(){
    printAllDivisors(36);

    return 0;
}