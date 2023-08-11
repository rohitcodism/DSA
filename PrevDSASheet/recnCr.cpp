#include<iostream>
using namespace std;
int comb(int n,int r){
    if(n==r||r==0){
        return 1;
    }else{
        return comb(n-1,r-1)+comb(n-1,r);
    }
}
int main(){
    int x,y,p;
    cout<<"Enter the number"<<endl;
    cin>>x;
    cout<<"Enter the probs."<<endl;
    cin>>y;
    p=comb(x,y);
    cout<<"The result of this combination is "<<p<<endl;
}