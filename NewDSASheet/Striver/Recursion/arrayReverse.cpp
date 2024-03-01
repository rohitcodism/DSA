#include<bits/stdc++.h>
using namespace std;

void revArray(int a[], int lb, int ub){  //* Using two parameter
    
    if(lb >= ub){
        return;
    }

    swap(a[lb], a[ub]);
    revArray(a,lb+1,ub-1);
}

void revArray2(int a[], int lb){    //* Using One parameter

    int n = 6;

    if(lb>=n-lb-1){
        return;
    }
    swap(a[lb], a[n-lb-1]);
    revArray2(a,lb+1);
}

void displayArray(int arr[], int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}

int main(){

    int arr[6] = {1,2,3,4,5,6};

    revArray2(arr,0);

    displayArray(arr,6);

    return 0;
}