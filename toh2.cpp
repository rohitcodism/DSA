#include<iostream>
using namespace std;
void TOH(int n, int a, int b, int c){
    if(n>0){
        TOH(n-1,a,c,b);
        cout<<"from"<<a<<"to"<<c<<endl;
        TOH(n-1,b,a,c);
    }
}
int main(){
    int n,a,b,c;
    cout<<"Enter the number of disks : "<<endl;
    cin>>n;
    cout<<"Enter the tower numbers : ";
    cin>>a>>b>>c;
    TOH(n,a,b,c);
    return 0;
}