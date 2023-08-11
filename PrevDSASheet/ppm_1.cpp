#include<iostream>
using namespace std;
<<<<<<< HEAD
//in pass by value method if the formal parameter is changed then there is no change in actual parameter
//pass by value is used when we want a function to process soemthing and return the result
//if a function is modifying actual parameters then it may or may not return result
int add(int x, int y){
    int z;
    x++;
    cout<<x<<endl;
=======
int add(int x, int y){
    int z;
>>>>>>> db1cfe941337f5ed1e5f435930269393fa672ddb
    z = x + y;
    return z;
}
int main(){
    int a,b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    cout<<"The sum of "<<a<<" and "<<b<<" is "<<add(a,b)<<endl;
<<<<<<< HEAD
    cout<<a<<endl;
=======
>>>>>>> db1cfe941337f5ed1e5f435930269393fa672ddb
}