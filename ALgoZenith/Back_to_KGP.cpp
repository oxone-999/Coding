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
    lli n,m;
    cin>>n>>m;

    vector<pair<lli,lli>> adj[n+1];
    for(lli i=0;i<m;i++){
        lli u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
    }

    lli dist[n+1];
    lli cnt[n+1];
    lli mn[n+1];
    lli mx[n+1];

    for(lli i=1;i<=n;i++){
        dist[i] = 1e18;
        cnt[i] = 0;
        mn[i] = 0;
        mx[i] = 0;
    }

    dist[1] = 0;
    cnt[1] = 1;

    priority_queue<pair<lli,lli> ,vector<pair<lli,lli>> , greater<pair<lli,lli>>> pq;

    pq.push({0,1});

    while(!pq.empty()){
        pair<lli,lli> x = pq.top();
        pq.pop();

        lli u = x.second;
        lli distance = x.first;
        if(distance > dist[u]) continue;

        for(auto it:adj[u]){
            lli v = it.first;
            lli w = it.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                pq.push({dist[v],v});
            }else if(dist[v] == dist[u] + w){
                cnt[v] += cnt[u];
                cnt[v] %= mod;
                mn[v] = min({mn[v], mn[u] + 1, mx[u] + 1});
                mx[v] = max({mx[v], mx[u] + 1, mn[u] + 1});
            }
        }
    }
    if(dist[n] == 1e18) cout<<(-1)<<endl;
    else cout<<dist[n]<<" "<<cnt[n]<<" "<<mn[n]<<" "<<mx[n];
}

signed main(){
    IOS
    solve();
    return 0;
}