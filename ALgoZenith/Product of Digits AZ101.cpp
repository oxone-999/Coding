//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    int prod = 1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        prod *= x;
        prod %= MOD;
    }

    cout<<prod%MOD<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}