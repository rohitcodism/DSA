#include<iostream>
using namespace std;

int gpwsd(int b, int n1, int d2){
    int carry=0;
    int ans=0;
    int power=1;
    while(n1!=0||carry!=0){
        int l1=n1%10;
        n1/=10;
        int product=l1*d2+carry;
        int q=product/b;
        int r=product%b;
        ans+=(r*power);
        carry=q;
        power*=10;

    }
    return ans;
    
}
int getsum(int b,int n1,int n2){
    int carry =0;
    int ans=0;
    int power=1;
    while(n1!=0||n2!=0||carry!=0){
        int ld1=n1%10;
        int ld2=n2%10;
        n1/=10;
        n2/=10;
        int sum= ld1+ld2+carry;
        int q=sum/b;
        int r=sum%b;
        ans+=(r*power);
        carry=q;
        power*=10;
    }
    return ans;

}
int getproduct(int b,int n1,int n2){
    int ans=0;
    int power=1;
    while(n2!=0){
        int l2=n2%10;
        n2/=10;
        int pwsd=gpwsd(b,n1,l2);
        ans=getsum(b,ans,pwsd*power);
        power*=10;

    }
    return ans;


}

int main(){
    int b,n1,n2;
    cin>>b>>n1>>n2;
    cout<<getproduct(b,n1,n2)<<endl;
    }
