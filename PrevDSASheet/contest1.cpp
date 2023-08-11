#include<iostream>
using namespace std;
struct Array{
int *p;
int *q;
int length;
int size;
};
struct Array* Revperm(struct Array *arr1){
    int i,j,k;
    struct Array *perm = (struct Array *)malloc(sizeof(struct Array));
    for(i = 0,j = 1;j<arr1->length;i++,j++){
        if(arr1->p[i]!= 0 || arr1->p[j] != 0 && arr1->p[i] == arr1->p[j] ){
            cout<<"Its not a permutation."<<endl;
            break;
        }else{
            perm->q[k++] == arr1->p[i];
        }
    }
    perm->length == k;
    perm->size == arr1->length;
    return perm;
}
int main(){
    int length,elements,i,j,k;
    struct  Array perm;
    cout<<"Enter the length of the permutation  : ";
    cin>>length;
    for(i = 0;i<perm.length;i++){
        cin>>perm.p[i];
    }
    cout<<"The revised permutation is : "<<Revperm(&perm)<<endl;

}