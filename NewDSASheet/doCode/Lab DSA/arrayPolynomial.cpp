// implementation of the Polynomial expression using stack using array


#include<iostream>
#include<cmath>
using namespace std;

class Poly{
    int capacity;
    int size;
    int top;
    int *coeff;
    int *exp;

    public:
    Poly(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->top = -1;
        this->coeff = new int[capacity];
        this->exp = new int[capacity];
    }

    void Display(){
        int i = 0;
        cout<<"Stack is : "<<endl;
        while(i<size){
            cout<<this->coeff[i]<<'x^'<<this->exp[i]<<endl;
            i++;
        }
    }

    bool isUnderFlow(){
        return top == -1;
    }

    bool isOverFlow(){
        return this->size == this->capacity;
    }

    void push(int coeff, int exp){
        if(isOverFlow()){
            cout<<"Stack Overflow!!!"<<endl;
            return;
        }
        this->coeff[++top] = coeff;
        this->exp[++top] = exp;
    }

    int* pop(){
        if(isUnderFlow()){
            cout<<"Stack underflow!!!"<<endl;
            return nullptr;
        }
        int x = this->coeff[top--];
        int y = this->exp[top--];

        int popped[] = {x,y};

        return popped;
    }

    int* peek(){
        if(isUnderFlow()){
            cout<<"Stack underflow!!!"<<endl;
            return nullptr;
        }
        
        int peeked[] = {this->coeff[top], this->exp[top]};

        return peeked;
    }

    void eVal(int x){
        if(isUnderFlow()){
            cout<<"Stack Underflow!!!"<<endl;
            return;
        }

        int sum = 0;
        int i = 0;
        while(i<size){
            sum+= this->coeff[i]*pow(this->exp[i],x);
            i++;
        }
        cout<<"The evaluated sum for x = "<<x<<" is  : "<<sum<<endl;
    }
};

int main()
{

    int capacity;
    cout<<"Enter the capacity of the stack : ";
    cin>>capacity;
    cout<<endl;

    Poly p(capacity);
    p.push(1, 2);
    p.push(2, 1);
    p.push(3, 0);
    p.Display();
    p.eVal(2);
    return 0;
}