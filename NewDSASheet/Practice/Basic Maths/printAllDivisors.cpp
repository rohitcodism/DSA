#include<bits/stdc++.h>
using namespace std;

void printFactors(vector<int>factors){

    sort(factors.begin(), factors.end());

    cout<<endl;
    cout<<"The factors list is : "<<endl;

    for(auto it = factors.begin(); it != factors.end(); it++){
        cout<<*(it)<<"  ";
    }
    cout<<endl;
}

void printSet(set<int>factors){

    cout<<endl;
    cout<<"The factors in the set is : ";

    for(auto it = factors.begin(); it != factors.end(); it++){
        cout<<*(it)<<"  ";
    }
    cout<<endl;
}

void printAllDivisors(int n){
    
    vector<int>factors;

    set<int>factors2;

    for(int i = 1; i*i <= n;i++){ 
        //** --> +if 36 = 1*36 then 1 and 36 both are factors or divisors of 36 so that's why it is n/2 instead of n in the for loop.
        if(n%i == 0){
            factors.emplace_back(i);
            factors2.insert(i);
            if((n/i) != i){
                factors.emplace_back(n/i);
                factors2.insert(n/i);
            }
        }
    }

    // printFactors(factors);

    printSet(factors2);
}

int main(){
    printAllDivisors(36);

    return 0;
}

/*
    * 1 * 36 = 36
    * 2 * 18 = 36
    * 3 * 12 = 36
    * 4 * 9 = 36
    * 6 * 6 = 36
    * 
    * total sqrt(36) times the loop will run.
    * 
    * We should use a SET to store the factors of a number.
    * 
    * As sqrt is function in STL so it can increase the time complexity as it will run every time the loop will iterate.
*/