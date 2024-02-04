#include<iostream>
using namespace std;

void merge(int a[], int low, int mid, int high){

    // setting the length for sub-arrays
    int n1 = mid-low+1;
    int n2 = high-mid;

    // initializing the sub-arrays
    int left[n1],right[n2];

    // copying elements into left sub-array
    for(int i = 0;i< n1;i++){
        left[i] = a[low+i];
    }

    // copying elements into right sub-array
    for(int j = 0;j<=n2;j++){
        right[j] = a[mid + 1 + j];
    }

    // sorting two sub-arrays
    int i = 0,j = 0,k = low;

    while(i<n1 && j<n2){
        if(i<n1 && j<n2){
            a[k++] = left[i++];
        }
        else{
            a[k++] = right[j++];
        }
    }

    while(i<n1){
        a[k++] = left[i++];
    }
    while(j<n2){
        a[k++] = right[j++];
    }
}

void mergeSort(int a[], int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}


int main(){
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    cout<<endl;
    int a[n];
    cout<<"Enter all the elements in the array : "<<endl;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}