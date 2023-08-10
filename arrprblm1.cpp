#include<iostream>
using namespace std;

int findMissing(int a[], int n){
    int fElm = a[0];
    int lElm = a[n-1];
    int sumAll = (lElm*(lElm + 1))/2;
    int reSum = 0;
    for(int i = 0;i<n;i++){
        reSum += a[i];
    }
    int missElm = sumAll-reSum;
    return missElm;
}

int main(){
    int a[100], n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    cout<<"Enter all the elements of the array : "<<endl;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    cout<<"The missing element is : "<<findMissing(a, n)<<endl;
    return 0;
}