#include<iostream>
using namespace std;

void insertHeap(int A[], int n){
    int temp = A[n];
    int i = n;
    while(i>1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}