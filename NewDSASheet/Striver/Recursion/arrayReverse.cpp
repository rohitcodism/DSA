#include<bits/stdc++.h>
using namespace std;

void revArray(int a[], int lb, int ub){
    
    if(lb == ub || lb > ub){
        return;
    }

    swap(a[lb], a[ub]);
    revArray(a,lb+1,ub-1);
}

void displayArray(int arr[], int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}

int main(){

    int arr[5] = {1,2,3,4,5};

    revArray(arr,0,4);

    displayArray(arr,5);

    return 0;
}