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

    lli dist[n+5][n+5];

    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=n;j++){
            dist[i][j] = 0;
            if(i != j) dist[i][j] = 1e18;
        }
    }

    for(lli i=0;i<m;i++){
        lli a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = min(dist[a][b],c);
    }

    for(lli k=1;k<=n;k++){
        for(lli i=1;i<=n;i++){
            for(lli j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(lli i=0;i<q;i++){
        lli u,v;
        cin>>u>>v;
        if(dist[u][v] == 1e18){
            cout<<(-1)<<endl;
        }
        else cout<<dist[u][v]<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}