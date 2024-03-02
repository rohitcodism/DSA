#include<bits/stdc++.h>
using namespace std;

bool paliChecker(string s, int lb, int ub){
    if(lb >= ub)
        return true;
    if(s[lb] != s[ub])
        return false;

    paliChecker(s,lb+1,ub-1);
}

bool paliChecker2(string s,int lb){
    int n = 5;

    if(lb>=n-lb-1)
        return true;
    if(s[lb] != s[n-lb-1])
        return false;
    paliChecker2(s,lb+1);
}

int main(){

    paliChecker2("madam",0) ? cout<<"Palindrome"<<endl : cout<<"Not a palindrome."<<endl;
    return 0;
}