#include<bits/stdc++.h>
using namespace std;

void printSet(multiset<int>ms){
    for(auto it = ms.begin();it != ms.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
}

void explainMultiSet(){

    multiset<int> ms;

    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);
    ms.insert(5);
    ms.insert(7);

    printSet(ms);

    ms.erase(1);

    int cnt = ms.count(2);

    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1));
}

int main(){
    explainMultiSet();

    return 0;
}