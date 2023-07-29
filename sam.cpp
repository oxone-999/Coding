#include <bits/stdc++.h>
using namespace std;

#define int long long

void Checker(int n,int root)
{
    int lo =0;
    int hi = n;
    while(lo<=hi)
    {
        double mid = lo + (hi-lo)/2;
        double val = 1.0;
        for (int i = 0; i < root; i++)
        {
           val *= mid;
        }
        
        if(val == (double)n) {cout<<"YES\n";return;}
        else {cout<<"YES\n";return;}

        if(val < n)
        {
            lo = mid + 0.0000001;
        }
        else
        {
            hi = mid - 0.0000001;
        }
    } 
    cout <<"NO\n";return;
}

void solve()
{
    int q,n;
    cin >> q >> n;
    if(n==1) {cout << "YES\n" ;return;} 
    if(q==1) Checker(n,2);
    else if(q==2) Checker(n,3);
}   
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t;cin >> _t;  while(_t--)
    solve();
}