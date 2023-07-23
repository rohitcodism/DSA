#include<iostream>
using namespace std;
void fun(int A[], int n){
    int i;
    for(int i= 0; i<n;i++){
        cout<<"element "<<i<<" is : "<<A[i]<<endl;
    }
     cout<<"length of array : "<<sizeof(A)/sizeof(int)<<endl;
}
int main(){
    int A[5] = {2,4,6,8,10};
    fun(A,5);
    for(int x:A){
        cout<<"numbers are : "<<x<<" "<<endl;
        fun(A,5);
}
}