#include<bits/stdc++.h> // contains all the libraries for c++
using namespace std;

void explainPair(){
    pair<int, float> p = {1, 8.7};

    pair<int, pair<float, char>> p2 = {1, {3.8, 'a'}};

    pair<int, int> arr[] = {{1,3}, {2,7}, {3,9}};

    cout<<"------First Pair------"<<endl;
    cout<<"p.first : "<<p.first<<endl;
    cout<<"p.second : "<<p.second<<endl;

    cout<<"------Second Pair------"<<endl;
    cout<<p2.first<<endl;
    cout<<p2.second.first<<endl;
    cout<<p2.second.second<<endl;;

    cout<<"------Pair Array------"<<endl;
    cout<<arr[0].first<<endl;
}

int main(){
    explainPair();
    return 0;
}