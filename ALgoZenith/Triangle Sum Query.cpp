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
    
    vector<vector<lli>> vec(n+2,vector<lli>(m+2,0));

    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=m;j++){
            cin>>vec[i][j];
        }
    }


    vector<vector<lli>> pre(n+2,vector<lli>(m+2,0));

    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=m;j++){
            pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + vec[i][j];
        }
    }

    vector<vector<lli>> v(n+2,vector<lli>(m+2,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            v[i][j] = v[i-1][j-1] + pre[i][j];
        }
    }

    for(lli i=0;i<q;i++){
        lli x1,y1,l;
        cin>>x1>>y1>>l;
        lli ans = 0;

        ans += v[x1][y1];
        ans %= mod;
        if(x1-l >= 0 && y1-l >= 0) ans -= v[x1-l][y1-l];
        ans %= mod;
        y1--;
        lli x = v[x1][y1];
        if(x1-l+1 >= 0 && y1-l+1 >= 0) x -= v[x1-l+1][y1-l+1];
        ans -= x;
        ans %= mod;
        y1++;
        if(x1-l >= 0) ans -= pre[x1-l][y1];
        ans %= mod;
        if(x1-l+1 >= 0 && y1-l >= 0) ans -= pre[x1-l+1][y1-l];
        ans %= mod;
        if(x1-l >= 0 && y1-l >= 0) ans += pre[x1-l][y1-l];
        ans %= mod;

        if(ans < 0) ans += mod;
        else if(ans >= mod) ans -= mod;

        cout<<ans<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}