#include<iostream>
using namespace std;
struct Array{
int A[10];
int size;
int length;
};
void Display(struct Array arr){
    int i;
    cout<<"Elements Are : "<<endl;
    for(i = 0;i<arr.length;i++){
        cout<<arr.A[i]<<endl;
    }
}
void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int linearsearch(struct Array *arr,int key){
    int i = 0;
    for(i = 0;i<arr->length;i++){
        if(key==arr->A[i]){
        return i;
        swap(arr->A[i],arr->A[i-1]);
        }
    }
    return -1;
}
int main(){
    struct Array arr = {{2,3,4,5,6},10,5};
    cout<<"The searched element is in : "<<linearsearch(&arr,6)<<endl;
    Display(arr);
}