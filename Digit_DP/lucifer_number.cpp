#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isPrime(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

const int mod = 1e9+7;
int len;
string L,R;

int dp[10][2][2][50][50][3];

int rec(int level,int tlo,int thi,int sumO,int sumE,int mode,int num){
    if(level == len){
        // cout<<sumO<<" "<<sumE<<" ";
        cout<<sumO-sumE<<" ";
        cout<<num<<" "<<endl;
        if(sumO > sumE && isPrime(sumO-sumE)) return 1;
        else return 0;
    }

    if(dp[level][tlo][thi][sumO][sumE][mode] != -1)
        return dp[level][tlo][thi][sumO][sumE][mode];
    
    int ans = 0;
    int lo = 0;
    if(tlo) lo = L[level] - '0';
    int hi = 9;
    if(thi) hi = R[level] - '0';

    // cout<<lo<<" "<<hi<<endl;

    for(int i=lo;i<=hi;i++){
        int n_mode = mode;
        if(n_mode == 0 && i != 0) n_mode = 1;
        else if(n_mode == 1) n_mode = 2;
        else if(n_mode == 2) n_mode = 1;

        int ntlo = tlo;
        if(i != L[level]-'0') ntlo = 0;

        int nthi = thi;
        if(i != R[level]-'0') nthi = 0;

        if(n_mode == 1) ans += rec(level+1,ntlo,nthi,sumO+i,sumE,n_mode,num*10 + i);
        else if(n_mode == 2) ans += rec(level+1,ntlo,nthi,sumO,sumE+i,n_mode,num*10 + i);
        else ans += rec(level+1,ntlo,nthi,sumO,sumE,n_mode,num*10 + i);
        ans %= mod;
    }
    return dp[level][tlo][thi][sumO][sumE][mode] = ans;
}

void solve()
{
    cin>>L>>R;
    if(stoi(L) < 10 && stoi(R) < 10)
    {
        cout<<0<<endl;
        return;
    }
    else if(stoi(L) < 10) L = "10";
    int cnt = R.size()-L.size();
    string temp = "";
    while(cnt--)
        temp += '0';

    L = temp + L;
    len = R.size();

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0,0,0,0)<<endl;
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