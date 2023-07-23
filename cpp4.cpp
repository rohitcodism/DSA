#include<iostream>
using namespace std;

int getdigitfrequency(int n,int d){
    int counter=0;
    while(n!=0){
        int r = n % 10;
        n /= 10;
        if(r==d){
            counter++;
            
        }
    }
    return counter;
}
int main(){
 int n,d;
 cin>>n>>d;
 cout<<getdigitfrequency(n,d)<<endl;

    
}