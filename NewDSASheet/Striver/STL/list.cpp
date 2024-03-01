#include<bits/stdc++.h>
using namespace std;

void print_list(list<int>ls){
    for(auto it = ls.begin(); it != ls.end(); it++){
        cout<<"Element a ls : "<<*(it)<<endl;
    };
}

void explainList(){
    list<int> ls;

    ls.push_back(1);

    ls.emplace_back(2);

    ls.push_front(3);

    ls.emplace_front(4);

    cout<<"------List 1------"<<endl;
    print_list(ls);

    // other functions are same as vector
}

int main(){
    explainList();
    return 0;
}