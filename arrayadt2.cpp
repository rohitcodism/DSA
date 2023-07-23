// #include<iostream>
// using namespace std;
// struct array{
//     int *a;
//     int size;
//     int length;
// };
// void display(struct array arr){
//     int i;
//     cout<<endl<<"All the elements are : "<<endl;
//     for(i = 0;i<arr.length;i++){
//         cout<<"Element "<<i+1<<" : "<<arr.a[i]<<endl;
//     }
// }
// int main(){
//     struct array arr;
//     int n,i;
//     cout<<"Enter the size of an array : "<<endl;
//     cin>>arr.size;
//     arr.a = (int * )malloc(arr.size*sizeof(int));
//     arr.length = 0;
//     cout<<"Enter number of numbers : "<<endl;
//     cin>>n;
//     cout<<"Enter all the elements : "<<endl;
//     for(i = 0;i<n;i++){
//         cin>>arr.a[i];
//     }
//     arr.length = n;
//     display(arr);
// }
// #include<iostream>
// using namespace std;
// struct array{
//     int *A;
//     int size;
//     int length;
// };
// void display(struct array arr){
//     int i;
//     for(i = 0;i<arr.length;i++){
//         cout<<"Elements "<<i+1<<" : "<<arr.A[i]<<endl;
//     }
// }
// int main( ){
//     struct array arr;
//     int n,i;
//     cout<<"Enter the size of an array : "<<endl;
//     cin>>arr.size;
//     arr.A = (int *)malloc(arr.size*sizeof(int));
//     arr.length = 0;
//     cout<<"Enter the nmuber of numbers : "<<endl;
//     cin>>n;
//     cout<<"Enter all the elements : "<<endl;
//     for(i = 0;i<n;i++){
//         cin>>arr.A[i];
//     }
//     arr.length = n;
//     display(arr);
// }
#include<iostream>
using namespace std;
struct array{
    int *a;
    int size;
    int length;
};
void display(struct array arr){
    int i;
    for(i = 0;i<arr.length;i++){
        cout<<arr.a[i]<<endl;
    }
}
int main(){
    struct array arr;
    int n,i;
    cout<<"Enter the size of an array : "<<endl;
    cin>>arr.size;
    arr.length = 0;
    cout<<"Enter the number of numbers : "<<endl;
    cin>>n;
    cout<<"Enter all the elements : "<<endl;
    for(i = 0;i<n;i++){
        cin>>arr.a[i];
    }
    arr.length = n;
    display(arr);
    return 0;
}