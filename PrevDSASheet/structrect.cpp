#include<iostream>
using  namespace std;
    struct r{
        int length;
        int breadth;
        int p;
    };
    int main(){
        struct r r1={10,5};
        cout<<sizeof(r1)<<endl;
        struct r r2={2*10+2*5};
        r1.length=15; 
        r1.breadth=20;
        cout<<r1.length<<endl;
        cout<<r1.breadth<<endl;
    }
