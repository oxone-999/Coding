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

    for(int i=0;i<q;i++){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        vec[x1][y1] += c;
        vec[x1][y2+1] -= c;
        vec[x2+1][y1] -= c;
        vec[x2+1][y2+1] += c;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vec[i][j] += vec[i-1][j] + vec[i][j-1] - vec[i-1][j-1];
        }
    }
    lli ans = LLONG_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans = max(ans,vec[i][j]);
        }
    }
    lli count = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vec[i][j] == ans) count++;
        }
    }
    cout<<ans<<" "<<count<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}