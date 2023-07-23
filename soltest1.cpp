#include<iostream>
using namespace std;
int main(){
    int nums[100];
    int n, i,j, x,y,target,flag;
    cout<<"Enter the length of the array : "<<endl;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    for(i = 0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the target : "<<endl;
    cin>>target;
    for(j = 0;j<n;){
        x = nums[j];
        y = target-nums[j];
        flag = 0;
        for(i = 0;i<n;i++){
            if(y == nums[i]){
                y = i;
                flag++;
                break;
            }
        }
        if(flag){
            cout<<"["<<j<<","<<y<<"]"<<endl;
            break;
        }
        else
            j++;
    }
}