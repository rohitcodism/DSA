#include<bits/stdc++.h>
using namespace std;

void print_deque(deque<int>deq){
    for(auto it = deq.begin(); it != deq.end(); it++){
        cout<<"Element a deq : "<<*(it)<<endl;
    };
}

void explainDeque(){
    deque<int> deq;

    deq.push_back(1);

    deq.emplace_back(2);

    deq.push_front(3);

    deq.emplace_front(4);

    cout<<"------Deque 1------"<<endl;
    print_deque(deq);

    // other functions are same as vector
}