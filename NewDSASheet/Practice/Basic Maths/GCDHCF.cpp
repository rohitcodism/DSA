#include<bits/stdc++.h>
using namespace std;

void GCDFinder(int x, int y){

    int gcd = 1;

    for(int i = 0;i<=min(x,y);i++){
        if(x%i == 0 && y%i == 0){
            if(i>gcd){
                gcd = i;
            }
        }
    }

    cout<<"The GCD of "<<x<<" & "<<y<<" is : "<<gcd<<endl;
}

int EuclideanFunction(int a, int b){

    if(!a)
        return b;
    if(!b)
        return a;
    else
        EuclideanFunction(max(a,b)%min(a,b), min(a,b));
}

int main(){
    int x,y;

    cout<<"Enter the first number : ";
    cin>>x;
    cout<<endl;

    cout<<"Enter the second number : ";
    cin>>y;
    cout<<endl;

    // GCDFinder(x,y);

    // Euclidean Function

    int gcd = EuclideanFunction(x,y);

    cout<<"The GCD of "<<x<<" & "<<y<<" is : "<<gcd<<endl;

    return 0;
}