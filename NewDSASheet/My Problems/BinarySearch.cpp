#include<iostream>

using namespace std;

int binarysearch(int arr[], int n, int k) {
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(arr[mid]==k){
                return mid;
            }
            else if(k>arr[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }

int main(){
    int n,k;
    cout<<"Enter num of element in array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element"<<" ";
        cin>>arr[i];
    }
    cout<<"enter the element you want to find ";
    cin>>k;
    int result=binarysearch(arr,n,k);

    if(result!=-1){
        cout<<"element found and the index is "<<result<<endl;
    }
    else{
        cout<<"element is not found ";
    }
    return 0;
}