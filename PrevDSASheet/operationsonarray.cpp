#include<iostream>
using namespace std;
class Array{
private :
    void Swap(int *x,int *y);
public :
    int *A;
    int size;
    int length;
    Array(){
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz){
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array(){
        delete []A;
    }
    void Display();
    void Append(int x);
    void Insert(int index,int x);
    int Delete(int index);
    int LinearSearch(int key);
    int Binarysearch(int key);
    int get(int index);
    void Set(int index,int x);
    int max();
    int min();
    int sum();
    float Avg();
    void Reverse();
    void reverse2();
    void shift();
    void InsertSort();
    int isSorted();
    void reArrange();
    Array* Merge(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Difference(Array *arr2);
};
void Array :: Display(){
    int i;
    cout<<"Elements are : "<<endl;
    for(i = 0;i<length;i++)
        cout<<A[i]<<endl;
}
void Array :: Append(int x){
    if(length<size)
        A[length++] = x;
}
void Array :: Insert(int index,int x){
    if(index>=0&&index<=length){
        for(int i = length;i>index;i--){
            A[i] = A[i-1];
        A[index] = x;
            length++;
        }
    }

}
int Array :: Delete(int index){
    int x;
    int i;
    if(index>=0 && index<=length){
        x = A[index];
        for(i = index;i<length-1;i++){
            A[i] = A[i+1];
            length--;
        }
        return x;
    }
    return 0;
}
int Array :: Linearsearch(int key) {
    int i = 0;
    for (i = 0; i < length; i++) {
        if (key == A[i]) {
            Swap(A[i], A[0]);
            return i;
        }
    }
    return -1;
}
int Array :: Binarysearch(int key){
    int l,mid,h;
    l = 0;
    h = length;
    while(l<=h){
        mid = (l+h)/2;
        if(key == A[mid]){
            return mid;
        }else if(key<A[mid]){
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return -1;
}
int Array :: get(int index){
    int i;
    for(i = 0;i<length;i++){
        if(index >= 0 && index<length){
            if(index == i){
                return A[i];
            }
        }
    }
    return -1;
}
void Array :: Set(int index,int x){
    if(index >= 0 && index < length){
        A[index] = x;
    }
}
int Array :: max(){
    int x = -32768;
    for(int i = 0;i<length;i++){
        if(A[i]>x){
            x = A[i];
        }
    }
    return x;
}
int Array :: min(){
    int x = A[0];
    for(int i = 1;i<length;i++){
        if(A[i]<x){
            x = A[i];
        }
    }
    return x;
}
int Array :: sum(){
    int s = 0;
    for(int i = 0;i<length;i++){
        s+=A[i];
    }
    return s;
}
float Array :: Avg(){
    int den = 0;
    float avg;
    for(int i = 0;i<length;i++){
        den++;
    }
    avg = sum()/den;
    return (float) avg;
}
void Array :: Reverse(){
    int *B;
    int i,j;
    B = new int[length];
    for(i = length-1,j = 0;i>=0;i--,j++){
        B[j] = A[i];
    }
    for(i = 0;i<length;i++){
        A[i] = B[i];
    }
}
void Array :: reverse2(){
    int i,j;
    for(i = 0,j = length-1;i<j;i++,j--){
        swap(A[i],A[j]);
    }
}void Array :: shift(){
    char s,l,r;
    cout<<"Enter the way you want to shift : "<<endl;
    cin>>s;
    if(s == 'l'){
    for(int i = 0;i<length;i++){
        A[i-1] = A[i];
    }
    A[length-1] = 0;
}else if(s == 'r'){
    for(int i = length-1;i>=0;i--){
        A[i+1] = A[i];
    }
    A[0] = 0;
}
}
int Array :: issorted(){
    int j = 0;
    for(int i = 1;i<length;i++){
        if(A[i-1]<A[i]){
            j++;
        }else{
            break;
        }
    }
    if(j == length-1){
        cout<<"Sorted"<<endl;
    }else{
        cout<<"unsorted"<<endl;
    }
}
Array* Union(Array arr2){
    int i,j,k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);
    while(i<length && j<length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = arr1->A[i++];
        }else if(arr1->A[i]>arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
        }else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for( ;i<arr1->length;i++){
        arr3->A[k++] = arr1->A[i];
    }
    for( ;j<arr2->length;j++){
        arr3->A[k++] = arr2->A[j++];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
Array* Intersection(Array *arr2){
    int i,j,k;
    i = j = k = 0;
    Array *arr3 = new int[length + arr2.length];
    while(i<length && j <arr2.length){
        if(A[i] < arr2.A[j]){
            i++;
        }
        else if(A[i] > arr2.A[j]){
            j++;
        }
        else if(A[i] == arr2.A[j]){
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;

}
Array* Merge(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(length+arr2.length); 
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }else{
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for( ;i<length;i++){
        arr3->A[k++] = A[i];
    }
    for( ;j<arr2.length;j++){
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;
    arr3->size = 10;
    return arr3;
}
struct Array* Difference(Array *arr2){
    int i,j,k;
    i = j = k = 0;
    Array *arr3 = new int[length + arr2.length]
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }else if(A[i]>arr2.A[j]){
            j++;
        }else{
            i++,j++;
        }
    }
    for( ;i<length;i++){
        arr3->A[k++] = A[i];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
int main(){
    Array *arr1;
    int ch;
    int x,index,size;
    cout<<"Enter the size : "<<endl;
    cin>>size;
    arr1 = new Array[size];
    do
    {
    cout<<"Menu : "<<endl<<"1. Insert\n"<<"2. Delete\n"<<"3. Search\n"<<"4. Sum\n"<<"5. Display\n"<<"6. Exit\n"<<endl;
    cout<<"Enter yuor choice : ";
    cin>>ch;
    switch(ch){
        case 1 :
        cout<<"Enter an element and index : "<<endl;
        cin>>x>>index;
        Insert(index,x);
        break;
        case 2 :
        cout<<"Enter the index : "<<endl;
        cin>>index;
        int x = Delete(index);
        cout<<"The deleted element is : "<<x<<endl;
        break;
        case 3 : 
        cout<<"Enter the key you want to found : "<<endl;
        cin>>x;
        cout<<"The searched element is in : "<<binarysearch(6)<<endl;
        break;
        case 4 :
        cout<<"sum of all the elements  in this array : "<<sum()<<endl;
        break;
        case 5 :
        Display();
        break;
        case 6 :
        break;
    }
  }while (ch<6);
    return 0;
}