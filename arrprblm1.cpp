#include<iostream>
using namespace std;

class Arrayprb{
    private:
        int a[100];
        int length;
        int size;
    public:
        Arrayprb(int n){
            size = 100;
            length = n;
        }

        void getData(){
            int i;
            for(i = 0;i<length;i++){
                cin>>a[i];
            }
        }

        int findMissing()
        {
            int fElm = a[0];
            int lElm = a[length - 1];
            int sumAll = (lElm * (lElm + 1)) / 2;
            int reSum = 0;
            for (int i = 0; i < length; i++)
            {
                reSum += a[i];
            }
            int missElm = sumAll - reSum;
            return missElm;
        }

        void missing2(){
            int fElm = a[0];
            int diff = fElm;
            int i, flag;
            for(i = 0;i<length;i++){
                if((a[i]-i)!=diff){
                    while(diff<(a[i]-i)){
                        cout<<"The missing element is : "<<(diff+i)<<endl;
                        diff++;
                        flag++;
                    }
                }
                if(!flag)
                    cout<<"There is no missing elements in the array."<<endl;
            }
        }
};

int main(){
    int n, x;

    cout<<"Enter the length of the array : ";
    cin>>n;

    // cout<<"Enter the option you want to perform : "<<endl;

    Arrayprb a1(n);

    cout<<"Enter all the elements : ";
    a1.getData();

    // cout<<"The missing element is : "<<a1.findMissing()<<endl;
    
    a1.missing2();
    return 0;
}