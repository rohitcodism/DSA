#include<iostream>
using namespace std;
void append(int a[], int n, int x){
    a[n] = x;
    n++;
}
void insert(int a[],int n, int x, int k){
    int i;
    n++;
    for (i = n-1; i > x; i--)
    {
        a[i] = a[i-1];
    }
    a[i] = k;

    
}
int del(int a[], int x, int n){
    int z = a[x];
    for(int i = x;i<n-1;i++){
        a[i] = a[i+1];
    }
    n--;
    return z;
}
int linearSearch(int a[], int length, int key){
    int i;
    for(i = 0;i<length;i++){
        if(key == a[i])
            return i;
    }
}
int rBinSearch(int a[],int length, int key,int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key < mid)
            return rBinSearch(a,length,key,l,mid-1);
        else
            return rBinSearch(a,length,key,mid+1,h);
    }
}
int getIndex(int a[],int length,int index){
    if(index>=0 && index<length)
        return a[index];
    else
        return -1;
}
void setIndex(int a[], int length, int index, int key){
    if(index>=0 && index<length){
        a[index] = key;
        cout<<"Value Setted Successfully."<<endl;
    }else
        cout<<"Error"<<endl;
}
int max(int a[], int length){
    int max = a[0];
    for(int i = 1;i<length;i++){
        if(a[i]> max)
            max = a[i];
    }
    return max;
}
void rev(int a[],int n){
    int i,j,temp;
    for(i = 0,j = n-1;i<j;i++,j--){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    cout<<"After reversing the array is : "<<endl;
    for(i = 0;i<n;i++){
        cout<<a[i]<<" "<<endl;
    }
}
void leftShift(int a[], int n,int x){
    int i,j;
    for(int j =0;j<x;j++){
        for(i = 0;i<n;i++)
            a[i] = a[i+1];
    }
    for(i = 1;i<=x;i++){
        a[n-i] = 0;
    }
    cout<<"After shifting the array is : "<<endl;
    for ( i = 0; i < n; i++)
    {
        /* code */
        cout<<a[i]<<" ";
    }
}
void rightShift(int a[], int n,int x){
    int i,j;
    for(int j =0;j<x;j++){
        for(i = n-1;i>0;i--)
            a[i] = a[i-1];
    }
    for(i = 0;i<x;i++){
        a[i] = 0;
    }
    cout<<"After shifting the array is : "<<endl;
    for ( i = 0; i < n; i++)
    {
        /* code */
        cout<<a[i]<<" ";
    }
}
void rotate(int a[], int n, int x){
    int i,t = 0;
    int temp[n];
    for(i = x;i<n;i++){
        temp[t] = a[i];
        t++;
    }
    for(i = 0;i<x;i++){
        temp[t] = a[i];
        t++;
    }
    for(i = 0;i<n;i++){
        a[i] = temp[i];
    }
    cout<<"After rotating the array is : "<<endl;
    for(i = 0;i<n;i++){
        cout<<a[i]<<"\t"<<endl;
    }
}
void rotate2(int a[], int n, int x){
    int i,t = 0;
    int temp[n];
    for(i = n-1;i>=n-x;i--){
        temp[t] = a[i];
        t++;
    }
    for(i = 0;i<n-x;i++){
        temp[t] = a[i];
        t++;
    }
    for(i = 0;i<n;i++){
        a[i] = temp[i];
    }
    cout<<"After rotating the array is : "<<endl;
    for(i = 0;i<n;i++){
        cout<<a[i]<<"\t"<<endl;
    }
}
int isSorted(int a[], int n){
    int buzz = 0;
    for(int i = 0;i<n;i++){
        if(a[i]>a[i+1])
            buzz++;
    }
    if(buzz)
        return 0;
    else
        return 1;
}
int main(){
    int a[100];
    int n;
    cout<<"Enter the length of the Array : ";
    cin>>n;
    cout<<"Enter the array elements : "<<endl;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    // append(a,5,4);
    // cout<<"The Array after appending : "<<endl;
    // for(int i =0;i<=n;i++){
    //     cout<<a[i]<<endl;
    // }
    // insert(a,5,3,11);
    // int x = del(a,3,n);
    // cout<<"The Deleted element is : "<<x<<endl<<"The Array Is : "<<endl;
    // for(int i = 0;i<n-1;i++)
    //     cout<<a[i]<<endl;
    // int k;
    // cout<<"Enter an element to search in the array : ";
    // cin>>k;
    // int l = 0;
    // int h = n-1;
    // cout<<"The searched element is in the "<<rBinSearch(a,n,k,l,h)<<"th index of the array."<<endl;
    // int f;
    // cout<<"Enter the index no. to find the element : ";
    // cin>>f;
    // cout<<"The element in "<<f<<"th index is : ";
    // if(getIndex(a,n,f) != -1)
    //     cout<<getIndex(a, n, f)<<endl;
    // else
    //     cout<<"Invalid"<<endl;
    // int b;
    // cout<<"Enter an index to set the value : ";
    // cin>>b;
    // setIndex(a,n,b,7);
    // return 0;
    // cout<<"The max element is : "<<max(a,n)<<endl;
    // rev(a,n);
    // int x;
    // cout<<"How many times you want to rotate the array : ";
    // cin>>x;
    // rotate2(a,n,x);
    isSorted(a,n);
}