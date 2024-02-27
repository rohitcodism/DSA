#include<bits/stdc++.h>
using namespace std;

void printMap(map<int, int>mp){
    for(auto it = mp.begin();it != mp.end();it++){
        cout<<it->first<<"-->"<<it->second<<endl;
    }
}

void explainMap(){
    map<int, int>mp1;

    map<int, pair<int, int>> mp2;

    map<int, string>mp3;

    map<pair<int, int>, pair<int, char>>mp4;

    mp1[1] = 2; // {1, 2}

    mp1[3] = 10; // {1, 2}, {3, 10}

    mp2[4] = {2, 3}; // {4, {2, 3}}

    mp2[5].first = 1; // {4, {2, 3}}, {5, {1, 0}}

    mp3[1] = "abc"; // {1, "abc"}

    mp3[5] = "cdc"; // {1, "abc"}, {5, "cdc"}

    mp4[{1, 2}] = {2, 'a'}; // {{1, 2}, {2, 'a'}}

    mp4[{2, 3}] = {3, 'b'}; // {{1, 2}, {2, 3}}, {{2, 3}, {3, 'b'}}

    printMap(mp1);
}

int main(){
    explainMap();

    return 0;
}