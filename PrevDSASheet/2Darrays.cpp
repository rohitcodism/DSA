#include<iostream>
using namespace std;
int main(){
    int ** a;
    a = new int*[3];
    a[0] = new int[4];
    a[1] = new int[4];
    a[2] = new int[4];
    for(int i=0;i<3;i++){
        for(int i=0;i<4;i++){
            cout<<a[i]<<endl;
        }
    }
}