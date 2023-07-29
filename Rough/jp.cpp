#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="space in text";
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    cout<<s<<endl;
}