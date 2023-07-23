//if i change the element of an array then it will effect the actual parameter
//We can't use for each loop for a pointer to access or change or print its elements
#include<iostream>
using namespace std;
void fun(int *A, int n){
    cout<<"The size of the pointer : "<<sizeof(*A)/sizeof(int)<<endl;
    for(int i=0;i<5;i++)
    cout<<A[i]<<endl;
    A[0]=15;
}
int main(){
    int A[ ]={2,4,6,8,10};
    int n=5;
    fun(A,n);
    for(int x:A)
    cout<<"Element is : "<<x<<" ";
    return 0;
}