#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<endl;

    int arr[n];

    cout<<"Enter the elements: ";   
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<endl;

    map<int, int> mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    cout<<endl;

    while(q--){
        int num;
        cout<<"Enter the number to be searched: ";
        cin>>num;
        cout<<endl;

        cout<<"The number "<<num<<" is present "<<mpp[num]<<" times."<<endl;
        cout<<endl;
    }

    // cout<<"The frequency of each element is: "<<endl;
    // for(auto it : mpp){
    //     cout<<"The frequency of "<<it.first<<" is "<<it.second<<endl;
    // }

    return 0;
}