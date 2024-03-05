#include<bits/stdc++.h>
using namespace std;

void charHashing(string s){
    const int MAX_CHAR = 26;
    int count[MAX_CHAR] = {0};

    // Count the frequency of each character
    for(char c : s){
        count[c - 'a']++;
    }

    // Print the character and its frequency
    for(int i = 0; i < MAX_CHAR; i++){
        if(count[i] > 0){
            char c = i + 'a';
            cout << c << ": " << count[i] << endl;
        }
    }
}

int main(){
    string s = "hello world";
    charHashing(s);
    return 0;
}