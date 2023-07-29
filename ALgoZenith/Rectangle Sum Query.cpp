//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    lli n,m,q;
    cin>>n>>m>>q;

    vector<vector<lli>> vec(n+1,vector<lli>(m+1,0));

    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=m;j++){
            cin>>vec[i][j];
        }
    }

    vector<vector<lli>> pre(n+1,vector<lli>(m+1,0));

    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=m;j++){
            pre[i][j] = (pre[i-1][j]%mod + pre[i][j-1]%mod - pre[i-1][j-1]%mod + vec[i][j]%mod)%mod;
        }
    }

    for(lli i=0;i<q;i++){
        lli x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        lli ans = (pre[x2][y2]%mod - pre[x2][y1-1]%mod - pre[x1-1][y2]%mod + pre[x1-1][y1-1]%mod)%mod;
        ans %= mod;
        if(ans >= mod) ans -= mod;
        else if(ans < 0) ans += mod;
        cout<<ans<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}