#include<iostream>
using namespace std;

void isMissing(int a[], int n){
    int sum = (n*(n+1))/2;
    int sum2, i;
    for(i = 0;i<n;i++){
        sum2  += a[i];
    }
    cout<<"The missing element is : "<<(sum2)<<endl;
}

int main(){
    int a[50], i, n;
    cout<<"Enter the length of the array : "<<endl;
    cin>>n;
    for(i = 0;i<n;i++){
        cin>>a[i];
    }
    isMissing(a,n);
    cout<<n;
    return 0;
}