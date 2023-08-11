#include<iostream>
using namespace std;
bool isEven (int a){
  //for even retrurn 1;
  //for odd return 0;
  if(a&1){
    return 0;
  }else{
    return 1;
  }
}
 int main(){
  int num;
  cin>>num;
if (isEven(num)){
    cout<<"The number is Even"<<endl;
  }else{
    cout<<"The number is Odd"<<endl;
  }
 }
 
 
 


     
 
