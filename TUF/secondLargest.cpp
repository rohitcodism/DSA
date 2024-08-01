#include<bits/stdc++.h>
using namespace std;

void secondLarge(vector<int>& arr, int n){
    int largest = arr[0];
    int secondLargest = -1;

    for(int i = 0;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
    }

    if(secondLargest != -1){
        cout<<"Second largest eleement in the array: "<<secondLargest<<endl;
    }
    else{
        cout<<"No second largest element in the array"<<endl;
    }
}

int main(){
    
}