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

    unordered_map<int, int> mpp;

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

    // string Hashing
    string s = "hello world";

    map<char, int> mpp1;

    for(char c : s){
        mpp1[c]++;
    }

    // cout<<"The frequency of each character is: "<<endl;
    // for(auto it : mpp1){
    //     cout<<"The frequency of "<<it.first<<" is "<<it.second<<endl;
    // }

    cout<<"Enter the number of queries: ";
    cin>>q;
    cout<<endl;
    while(q--){
        char c;
        cout<<"Enter the character to be searched: ";
        cin>>c;
        cout<<endl;

        cout<<"The character "<<c<<" is present "<<mpp1[c]<<" times."<<endl;
        cout<<endl;
    }

    return 0;
}