//An array created in heap can be accessd from the main or by the main function if it has a pointer on it
//In this code fuction(fun) is creating an array but as it has a pointer on it so it can be accessed by the main function
//Anything created in the heap can be accessed from anywhere in the code if it has a pointer on it
//It is returning the address of the memory and from main function we can access it 
#include<iostream>
using namespace std;
int * fun (int size){
int * p;
p = new int[size];
for(int i=0;i<size;i++)
p[i]=i+1;
return p; // It is returning the pointer of the array 
}
int main(){
    int *ptr, sz=7;//Here ptr the is accessing the array by the returned pointer from fun function
    ptr = fun(sz);
    for(int i=0;i<sz;i++)
    cout<<ptr[i]<<endl;
    return 0;
}