int incr(int *a){
    *a++;
    return *a;
}

#include<iostream>
using namespace std;
int main(){
    // int a=10;
    // int *p;
    // p = &a;
    // // cout<<*p<<endl;
    // // *p = 20;
    // // cout<<*p<<endl;
    // // cout<<p<<endl;
    // // p++;
    // // cout<<p<<endl;
    // a++;
    // cout<<*p<<endl;
    // int arr[] = {1,2,3,4,5};
    // int *p = arr;
    // for(int i = 0;i<5;i++){
    // cout<<*(arr+i)<<endl;
    // p++;
    // }
    // int a = 10;
    // int *p = &a;
    // cout<<p<<endl;
    // int **q = &p;
    // cout<<q<<endl;
    // cout<<*q<<endl;
    // cout<<**q<<endl;
    int a = 2;
    int *p = &a;
    cout<<incr(&a)<<endl;
}    