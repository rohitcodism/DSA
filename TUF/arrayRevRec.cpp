#include<bits/stdc++.h>
using namespace std;

void RevRec(vector<int>& arr, int i, int n){
    if(i>n/2){
        return;
    }

    swap(arr[i], arr[n-i-1]);
    RevRec(arr,i+1,n);
}

int main(){
    vector<int> arr = {1,2,3,4,5, 6};

    RevRec(arr,0,arr.size());

    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}