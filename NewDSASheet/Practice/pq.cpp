#include<bits/stdc++.h>
using namespace std;

void printPriorityQueue(priority_queue<int> pq){
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    cout<<endl;
}

void explainPriorityQueue(){


    priority_queue<int> pQ1; // Max-Heap

    pQ1.push(2);
    pQ1.push(4);
    pQ1.push(7);
    pQ1.push(1);
    pQ1.push(9);
    printPriorityQueue(pQ1);


    pQ1.pop();
    printPriorityQueue(pQ1);

    priority_queue<int, vector<int>, greater<int>> pq2; // Min-Heap
}

int main(){
    explainPriorityQueue();

    return 0;
}