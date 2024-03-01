#include<bits/stdc++.h>
using namespace std;

int reverseDigit(int n){

    if(!n){
        cout<<0<<endl;
        return 0;
    }

    int revNum = 0;

    while(n){
        int r = n%10;

        revNum = revNum*10 + r;

        n = n/10;
    }
    return revNum;
}

bool checkPalindrome(int n){

    int revNum = reverseDigit(n);

    if(revNum == n)return true;
    return false;

}

bool checkAmstrong(int n){
    int sum = 0;

    string strNum = to_string(n);

    int digitLength = strNum.length();

    int dup = n;

    while(n){
        int r = n%10;

        sum += pow(r,digitLength);

        n = n/10;
    }

    if(dup == sum)return true;
    return false;
}

int main(){
    int revNum = reverseDigit(40110);

    cout<<"Reversed Number will be : "<<revNum<<endl;

    if(checkPalindrome(121))cout<<"Palindrome"<<endl;

    else cout<<"Not Palindrome"<<endl;

    if(checkAmstrong(3711))cout<<"Amstrong"<<endl;

    else cout<<"Not Amstrong"<<endl;

    return 0;
}