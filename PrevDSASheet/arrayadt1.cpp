// #include<iostream>
// using namespace std;
// int main(){
//     int A[5];
//     A[1] = 15;
//     cout<<A[1]<<endl;
//     cout<<A[0]<<endl;
//     for(int i=0;i<5;i++){
//         cout<<"for : "<<A[i]<<endl;
//     }
//     cout<<*(A+1)<<endl;
//     cout<<1[A]<<endl;
//     return 0;
// }
#include<iostream>
using namespace std;
int main(){
    int a[5] = {2,3,5,6,7};
    int *p;
    p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;
    for(int i=0;i<5;i++){
        cout<<"static"<<endl<<a[i]<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<"dynamic"<<endl<<p[i]<<endl;
    }
return 0;
}
