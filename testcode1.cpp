// #include<iostream>
// using namespace std;
// int fun(int n){
//     while (n>0){
//         cout<<n<<endl;
//         n--;
//     }
//     return 0;
// }
// int main(){
//     int a=3;
//     cout<<fun(a)<<endl;
// }
// #include<iostream>
// using namespace std;
// int sofn(int n){
//     if(n){
//         return sofn(n-1)+n;
//     }else{
//         return 0;
//     }
// }
// int main(){
//     int n;
//     cout<<"enter the number upto you want to sum"<<endl;
//     cin>>n;
//     cout<<"The sum is : "<<sofn(n)<<endl;
//     return 0;
// }
// #include<iostream>
// using namespace std;
// int fact(int n){
//     if(n){
//         return fact(n-1)*n;
//     }else{
//         return 1;
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter the number : "<<endl;
//     cin>>n;
//     int x = fact(n);
//     cout<<"The factorial is  : "<<x<<endl;
// }
// #include<iostream>
// using namespace std;
// int pow(int n, int e){
//     if(n = 0)
//         return 0;
//     else if(e = 0)
//         return 1;
//     else
//         return pow(n,e-1)*n;
// }
// int main(){
//     int n,e;
//     cin>>n>>e;
//     cout<<pow(n,e)<<endl;
// }
#include<iostream>
using namespace std;
int F[10];
int fib(int n){
    if(n<=1){
        return n;
    }else{
        return fib(n-2)+fib(n-1);
    }
}
int recfib(int n){
    if(n<=1){
        return n;
    }else{
        if(F[n-2] == -1){
            F[n-2] = fib(n-2);
        }if(F[n-1] == -1){
            F[n-1] = fib(n-1);
        }
        return F[n-2]+F[n-1];
    }
}
int main(){
    int i,n;
    cout<<"Enter the position of the Fibonacci Sequence : ";
    cin>>n;
    for(i = 0;i<10;i++)
        F[i] = -1;
    cout<<recfib(n)<<endl;
    cout<<"The fibonacci sequence till the position is : "<<endl;
    for(i = 0;i<n+1;i++){
        cout<<F[i]<<endl;
    }
    return 0;
}