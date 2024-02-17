#include<iostream>
using namespace std;
void merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int arr1[50];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            arr1[k]=arr[i];
            i++;
        }
        else{
            arr1[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            arr1[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            arr1[k]=arr[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++){
        arr[k]=arr1[k];
    }
}

void mS(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mS(arr,lb,mid);
        mS(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
void print(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"enter n = ";
    cin>>n;
    int lb=0;
    int ub = n-1;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mS(arr,lb,ub);
    print(arr,n);
}