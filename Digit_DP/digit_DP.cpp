#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
int len;
int D;
string L,R;

int dp[10010][2][2][100];

int rec(int level,int tlo,int thi,int sumD){
    if(level == len){
        if(sumD == 0) return 1;
        else return 0;
    }

    if(dp[level][tlo][thi][sumD] != -1)
        return dp[level][tlo][thi][sumD];
    
    int ans = 0;
    int lo = 0;
    if(tlo) lo = L[level] - '0';
    int hi = 9;
    if(thi) hi = R[level] - '0';

    for(int i=lo;i<=hi;i++){
        int ntlo = tlo;
        if(i != L[level]-'0') ntlo = 0;

        int nthi = thi;
        if(i != R[level]-'0') nthi = 0;

        ans += rec(level+1,ntlo,nthi,(sumD+i)%D);
        ans %= mod;
    }
    return ans;
}

void solve()
{
    cin>>L>>R;
    cin>>D;
    int cnt = R.size()-L.size();
    string temp = "";
    while(cnt--)
        temp += '0';

    L = temp + L;
    len = R.size();

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0)<<endl;
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