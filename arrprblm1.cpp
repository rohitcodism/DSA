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

        int max(){
            int max1 = a[0];
            for(int i = 1;i<length;i++){
                if(a[i]>max1){
                    max1 = a[i];
                }
            }
            return max1;
        }

        int min(){
            int min1 = a[0];
            for(int i = 1;i<length;i++){
                if(a[i]<min1){
                    min1 = a[i];
                }
            }
            return min1;
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

        void missing3(){
            int x = max();
            int z = min();

            int marker = 0;
            int b[x+1] = {0};

            for(int i = 0;i<length;i++){
                if(!b[a[i]]){
                    b[a[i]]++;
                }
            }
            
            for(int i = z; i<x+1; i++){
                if(!b[i]){
                    cout<<"The missing element is : "<<i<<endl;
                    marker++;
                }
            }
            if(!marker){
                cout<<"No missing values in the array.";
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
    
    // a1.missing2();

    a1.missing3();

    return 0;
}