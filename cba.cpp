//the result of this call by address function is directly effecting the actual parameters
//if we have some variable and want to modify that variable then we should send it by address
#include<iostream>
using namespace std;
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int a,b;
    cout<<"Enter the first number"<<endl;
    cin>>a;
    cout<<"Enter the second number"<<endl;
    cin>>b;
    swap(a,b);
    cout<<"The first number is "<<a<<endl;
    cout<<"The second number is "<<b<<endl;
}