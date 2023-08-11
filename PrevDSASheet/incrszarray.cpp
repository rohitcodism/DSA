// #include<iostream>
// using namespace std;
// int main(){
//     int*p = new int[5];
//     int*q = new int[10];
//     p[0] = 1;
//     p[1] = 6;
//     p[2] = 7;
//     p[3] = 4;
//     p[4] = 9;
//     p[5] = 11;
//     p[6] = 12;
//     p[7] = 13;
//     p[8] = 14;
//     p[9] = 15;
//     for(int i=0;i<10;i++){
//         q[i] = p[i];
//     }
//     delete[]p;
//     p = q;
//     q  = NULL;
//     for(int i=0;i<=9;i++){
//     cout<<p[i]<<endl;
//     }
// }
#include<iostream>
using namespace std;
int main(){
   int *p, *q;
    p = new int[5];
    q = new int[10];
     p[0] = 1;
     p[1] = 6;
     p[2] = 7;
     p[3] = 4;
     p[4] = 9;
     p[5] = 11;
     p[6] = 12;
     p[7] = 13;
     p[8] = 14;
     p[9] = 15; 
     for(int i = 0;i<10;i++){
        p[i] = q[i];
     }
     delete []p;
     p = q;
     q = NULL;
     for(int i = 0;i<10;i++){
        cout<<p[i]<<endl;
     }
}