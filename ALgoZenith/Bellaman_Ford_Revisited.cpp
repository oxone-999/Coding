//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct Node{
    lli u,v,w;
};

void solve()
{
    lli n,m;
    cin>>n>>m;

    vector<Node> edges;

    for(lli i=0;i<m;i++){
        lli u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,-w});
    }

    lli dist[n+1];

    for(lli i=1;i<=n;i++){
        dist[i] = 1e18;
    }

    dist[1] = 0;

    for(lli i=0;i<n;i++){
        for(auto it:edges){
            lli u = it.u;
            lli v = it.v;
            lli w = it.w;
            dist[v] = min(dist[v],dist[u] + w);
        }
    }

    for(auto it:edges){
        lli u = it.u;
        lli v = it.v;
        lli w = it.w;

        if(dist[v] > dist[u] + w){
            cout<<(-1)<<endl;
            return;
        }
    }
    cout<<(-dist[n])<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}