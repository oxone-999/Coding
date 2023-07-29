// Description

// Given two strings, a and b, find and print the total number of ways to insert a character at any 
// position in the string a such that the length of the Longest Common Subsequence of characters in 
// the two strings increases by one.

#include<bits/stdc++.h>
using namespace std;

#define int long long

int LCS(string s1,string s2){
    int x = s1.size();
    int y = s2.size();

    int t[x+1][y+1];
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++){
            if(i == 0 || j == 0) t[i][j] = 0;
        }
    }

    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(s1[i-1] == s2[j-1]) t[i][j] = t[i-1][j-1] + 1;
            else t[i][j] = max(t[i][j-1],t[i-1][j]);
        }
    }
    return t[x][y];
}

void solve()
{
    string s1;
    string s2;
    cin>>s1>>s2;

    int x = LCS(s1,s2);
    cout<<x*x;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}