#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
int len;
string L;

int dp[100010][2];

int rec(int level,int tlo,string s,char prev,int lev){
    if(level == len){
        // cout<<s<<" ";
        return 1;
    }

    // if(dp[level][tlo] != -1)
    //     return dp[level][tlo];
    
    int ans = 0;
    int lo = 0; 

    if(level == len-1 || tlo)
        lo = L[level] - 'A';

    for(int i=lo;i<26;i++){
        int ntlo = tlo;
        char nprev = prev;

        if(i != L[level] - 'A'){
            // char ch = i+'A';
            // cout<<s<<" "<<ch<<endl;
            ntlo = 0;
            nprev = i;
            lev = level;
        } 
        else if(i == L[level]-'A' && level == len-1) 
        {
            if(nprev < L[lev]) continue;
        }

        string s1 = "";
        s1.push_back(i+'A');
        ans += rec(level+1,ntlo,s+s1,nprev,lev);
        ans %= mod;
    }
    return dp[level][tlo] = ans;
}

void solve()
{
    cin>>L;
    len = L.size();
    memset(dp,-1,sizeof(dp));
    string s;
    char ch = '1';
    cout<<rec(0,1,s,ch,0)-1<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}