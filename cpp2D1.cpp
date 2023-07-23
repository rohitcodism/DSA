#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE // not part of code just to beautify input output
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w" , stdout);
    #endif



    int savings;
    cin>>savings;

    if(savings>5000)  {
        if(savings>10000) {
            cout<<"roadtrip wth neha\n";
    } else {
        cout<<"shopping with neha\n";
    }
    } else if(savings>2000){
        cout<<"rashmi\n";
    } else {
        cout<<"friends\n";
    }


    return 0;


}


    
    
