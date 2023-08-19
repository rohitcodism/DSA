#include<iostream>
using namespace std;

int* preSum(int a[], int s, int n){
    int* b = new int[100];
    int sum = 0, lr, ur;
    for(int i = 0;i<n;i++){
        sum = 0;
        sum += a[i];
        lr = a[i];
        b[0] = lr;
        for(int j = i+1;j<n;j++){
            if(sum == s){
                b[1] = a[j-1];
                return b;
                break;
            }else{
                sum += a[j];
            }
        }
    }
    return 0;
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int* ptr = preSum(a, 7, 5);
    cout<<ptr[0]<<" "<<ptr[1];
    return 0;
}
