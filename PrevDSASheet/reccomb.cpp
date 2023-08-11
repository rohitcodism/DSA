#include<iostream>
using namespace std;
int reccomb(int n , int r){
    if(n == r || r == 0){
        return 1;
    }else{
        return reccomb(n-1,r-1)+reccomb(n-1,r);
    }
}
int main(){
    int n,r;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    cout<<"Enter the no. of general combination : ";
    cin>>r;
    cout<<"The no. of combinations are : "<<reccomb(n,r)<<endl;
    return 0;
}