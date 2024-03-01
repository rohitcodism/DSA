#include<bits/stdc++.h>
using namespace std;

void parameterized(int i, int sum){
    if(i<1){
        cout<<"The sum is : "<<sum<<endl;
        return;
    }
    parameterized(i-1, sum+i);
}

int main(){
    parameterized(6,0);

    return 0;
}