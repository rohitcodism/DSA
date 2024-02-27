#include<bits/stdc++.h>
using namespace std;

void printSet(set<int>s1){
    for(auto it = s1.begin();it != s1.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
}

void explainSet(){
    set<int>s1;

    s1.insert(1);
    s1.insert(2);
    s1.insert(0);

    printSet(s1);
}

int main(){
    explainSet();

    return 0;
}