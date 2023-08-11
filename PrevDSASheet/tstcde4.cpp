// #include<iostream>
// using namespace std;
// template<class T>
// class Arithmatic{
//     private :
//     T a;
//     T b;
//     public :
//     Arithmatic(T a,T b);
//     T add();
//     T sub();
// };
// template<class T>
// Arithmatic<T> :: Arithmatic(T a,T b){
//     this->a=a;
//     this->b=b;
// }
// template<class T>
// T Arithmatic<T> :: add( ){
//     T c;
//     c = a+b;
//     return c;
// }
// template<class T>
// T Arithmatic<T> :: sub( ){
//     T c;
//     c = a-b;
//     return c;
// }
// int main(){
//     Arithmatic<int> ar(1,5);
//     cout<<"The sum of these two integers is : "<<ar.add( )<<endl;
//     Arithmatic<float> fl(5.6,9.4);
//     cout<<"The substraction of these two floats are : "<<fl.sub( )<<endl;
//     Arithmatic<char> ch('B','A');
//     cout<<"The summation of the ASCII code of these two characters is : "<<ch.add( )<<endl;
// }
// #include<iostream>
// using namespace std;
// template<class T>
// class Arithmatic{
//     private :
//     T a;
//     T b;
//     public :
//     Arithmatic(T a,T b);
//     T add( );
//     T sub( );
// };
// template<class T>
// Arithmatic<T> :: Arithmatic(T a,T b){
//     this->a=a;
//     this->b=b;
// } 
// template <class T>
// T Arithmatic<T> :: add( ){
//     T c;
//     c = a+b;
//     return c;
// }
// template <class T>
// T Arithmatic<T> :: sub( ){
//     T c;
//     c = a-b;
//     return c;
// }
// #include<iostream>
// using namespace std;
// template<class T>
// class Arithmmatic{
//     private :
//     T a;
//     T b;
//     public :
//     Arithmatic(T a,T b);
//     T add( );
//     T sub( );
// }:
// template <class T>
// Arithmatic<T> :: Arithmatic(T a,T b){
//     this->a=a;
//     this->b=b;
// }
// template <class T>
// T Arithmmatic<T> :: add ( ){
// //     T c;
// //     c = a+b;
// //     return c;
// // }
// #include<iostream>
// using namespace std;
// template<class T>
// class Arithmatic{
//     private :
//     T a;
//     T b;
//     public :
//     Arithmatic(T a,T b);
//     T add( );
//     T sub( );
// };
// template<class T>
// Arithmatic<T> :: Arithmatic(T a,T b){
//     this->a=a;
//     this->b=b;
// // }
// // template<class T>
// // T Arithmatic<T> :: add( ){
// //     T c;
// //     c = a-b;
// //     return c;
// // }
// #include<iostream>
// using namespace std;
// template<class T>
// class Arithmatic{
//     private :
//     T a;
//     T b;
//     public :
//     Arithmatic(T a,T b);
//     T add( );
//     T sub( );
// };
// template<class T>
// Arithmatic<T> :: Arithmatic(T a,T b){
//     this->a=a;
//     this->b=b;
// }
// template<class T>
// T Arithmatic<T> :: add( ){
//     T c;
//     c = a+b;
//     return c;
// }
// #include<iostream>
// using namespace std;
// template<class T>
// class Arithmatic{
//     private :
//     T a;
//     T b;
//     public :
//     Arithmatic(T a,T b);
//     T add( );
//     T sub( );
// };
// template<class T>
// Arithmatic<T> :: Arithmatic(T a,T b){
//     this->a=a;
//     this->b=b;
// }
// template<class T>
// T Arithmatic<T> :: add( ){
//     T c;
//     c = a+b;
//     return c;
// }
// template<class T>
// T Arithmatic<T> :: sub( ){
//     T c;
//     c = a-b;
//     return c;
// }
// #include<iostream>
// using namespace std;
// class Rectangle{
//     private :
//     int length;
//     int breadth;
//     public :
//     Rectangle( ){
//         length = 0;
//         breadth = 0;
//     }
//     Rectangle(int l,int b){
//         length = l;
//         breadth = b;
//     }
//     int area(int l,int b){
//         int p = 2*(l-b);
//         return p;
//     }
//     int peremeter(int l,int b){
//         int p = 2*(l+b);
//         return p;
//     }
//     int changelength(int l){
//         length = l;
//         return l;
//     }
//};
// #include<iostream>
// using namespace std;
// template<class T>
// class Rectangle{
//     private :
//     T l = 0;
//     T b = 0;
//     public :
//     Rectangle(T l,T b);
//     T Area( );
//     T Peremeter( );
//     T Changelength( );
// };
// template<class T>
// Rectangle<T> :: Rectangle(T l,T b ){
//     this->l = l;
//     this->b = b;
// }
// template<class T>
// T Rectangle<T> :: Area( ){
//     T a;
//     a = l*b;
//     return a;
// }
// template<class T>
// T Rectangle<T> :: Peremeter( ){
//     T p;
//     p = 2*(l+b);
//     return p;
// }
// int main( ){
//     Rectangle<int> ar(1,5);
//     cout<<"The area of this Rectangle is : "<<ar.Area( )<<endl;
//     Rectangle<float> fl(5.6,4.5);
//     cout<<"The peremeter of the Rectangle : "<<fl.Peremeter( )<<endl;
//     Rectangle<float> fl2(5.7,8.6);
//     cout<<"The Area of the Rectangle : "<<fl2.Area( )<<endl;
// }
// #include<iostream>
// using namespace std;
// int f(int n){
//     static int i=1;
//     if(n>=5){
//     return n;
//     }else{
//     n = n+i;
//     i++;
//     return f(n);
// }
// }
// int main(){
//     cout<<f(1)<<endl;
// }
// #include<iostream>
// using namespace std;
// int main(){
//     unsigned int x[4][3] = {{1,2,3}, {4,5,6}, {7,8,9},{10,11,12}};
//     cout<<x+3<<*(x+3)<<*(x+2)+3<<endl;
// }
// #include<iostream>
// using namespace std;
// struct Array{
//     int A[10];
//     int size;
//     int length;
// };
// void Display(struct Array arr){
//     int i;
//     cout<<"Elements are : "<<endl;
//     for(i = 0;i<arr.length;i++){
//         cout<<arr.A[i]<<endl;
//     }
// }
// void Append(struct Array *arr,int x){
//     if(arr->length<arr->size){
//         arr->A[arr->length++] = x;
//     }
// }
// void Insert(struct Array *arr,int index,int x){
//     if(index>=0&&index<=arr->length){
//         for(int i = arr->length;i>index;i--){
//             arr->A[i] = arr->A[i];
//             arr->A[index] = x;
//             arr->length++;
//         }
//     }
// }
// int Delete(struct Array *arr,int index){
//     int x;
//     int i;
//     if(index>=0 && index<=arr->length){
//         x = arr->A[index];
//         for(i = index;i<arr->length;i++){
//             arr->A[i] = arr->A[i+1];
//             arr->length--;
//         }
//         return x;
//     }
//     return 0;
// }
// int main(){
//     struct Array arr = {{2,3,4,5,6},10,5};
//     Append(&arr,10);
//     Insert(&arr,12,11);
//     cout<<Delete(&arr,0)<<endl;
//     Display(arr);
//     return 0;
// }
// #include<iostream>
// using namespace std;
// struct Array{
//     int A[10];
//     int size;
//     int length;
// };
// void Display(struct Array arr){
//     int i;
//     cout<<"Elements are : "<<endl;
//     for(int i = 0;i<arr.length;i++){
//         cout<<arr.A[i]<<endl;
//     }
// }
// void Append(struct Array *arr,int x){
//     if(arr->length<arr->size){
//         arr->A[arr->length++] = x;
//     }
// }
// void Insert(struct Array *arr,int index,int x){
//     if(index>=0 && index<=arr->length){
//         for(int i = arr->length;i>index;i--){
//             arr->A[i] = arr->A[i-1];
//             arr->A[index] = x;
//             arr->length++;
//         }
//     }
// }
// int Delete(struct Array *arr,int index){
//     int x = 0;
//     if(index >= 0 && index < arr->length ){
//         x = arr->A[index];
//         for(int i = index;i<arr->length;i++){
//             arr->A[i] = arr->A[i+1];
//             arr->length--;
//             return x;
//         }
//     }
//     return 0;
// }
// struct Array* Intersection(struct Array* arr, struct Array* Arr) {
//     int i, j, k;
//     i = j = k = 0;
//     struct Array *arr2 = (struct Array*)malloc(sizeof(struct Array));
//     while (i < arr->length && j < Arr->length) {
//         if (arr->A[i] < Arr->A[j]) {
//             i++;
//         }
//         else if (arr->A[i] > Arr->A[j]) {
//             j++;
//         }else if (arr->A[i] == Arr->A[j]) {
//             arr2->A[k++] = arr->A[i++];
//             j++;
//         }
//     }
//     arr2->length = k;
//     arr2->size = 10;
//     return arr2;

// }
// int main(){
//     struct Array arr = {{2,3,4,5,6},10,5};
//     struct Array Arr = {{3,4,5,6,7},10,5} ;
//     struct Array *arr3;  
//      // Append(&arr,10);
//     // Insert(&arr,0,10);
//     // Delete(&arr,4);
//     arr3 = Intersection(&arr,&Arr);
//     Display(*arr3);
// }
// #include<iostream>
// #include"oops1.cpp"
// using namespace std;
// int main(){
//     hero h1;
// }
include<stdio.h>