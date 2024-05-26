#include<iostream>

using namespace std;

const int N=100;
char b[N][N];

void print_board(char b[N][N],int n){
    static int sol=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }
    sol++;
    cout<<"NUMBER OF SOLUTION "<<sol<<endl<<endl;
}


void solve(int col,char b[N][N],int n,int lr[],int ud[],int ld[]){
    if(col==n){
        print_board(b,n);
        return;
    }
    for(int row=0;row<n;row++){
        if(lr[row]==0 && ud[(n-1)+(col-row)]==0 && ld[(col+row)]==0){
            b[row][col]='Q';
            lr[row]=1;
            ud[(n-1)+(col-row)]=1;
            ld[(col+row)]=1;
            solve(col+1,b,n,lr,ud,ld);
            b[row][col]='.';
            lr[row]=0;
            ud[(n-1)+(col-row)]=0;
            ld[(col+row)]=0;
        }
    }
}
int main(){
    int n;
    cout<<"enter number of queen ";
    cin>>n;
    int lr[n],ud[2*n-1],ld[2*n-1];
    for(int i=0;i<n;i++){
        lr[i]=0;
    }
    for(int i=0;i<2*n-1;i++){
        ud[i]=0;
        ld[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]='.';
        }
    }
    solve(0,b,n,lr,ud,ld);
    return 0;
}