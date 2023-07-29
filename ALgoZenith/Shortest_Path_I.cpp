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
        adj[v].push_back({u,w});
    }

    priority_queue<pair<lli,lli> , vector<pair<lli,lli>> ,greater<pair<lli,lli>>> pq;

    lli dist[n+1];
    lli marked[n+1];
    for(lli i=1;i<=n;i++){
        dist[i] = 1e18;
        marked[i] = false;
    }

    dist[1] = 0;

    pq.push({dist[1],1});

    while(!pq.empty()){
        lli distance = pq.top().first;
        lli node = pq.top().second;
        pq.pop();

        if(marked[node]) continue;
        marked[node] = true;

        for(auto it:adj[node]){
            lli next = it.first;
            lli weight = it.second;
            if(dist[next] > dist[node] + weight){
                dist[next] = dist[node] + weight;
                pq.push({dist[next],next});
            }
        }
    }

    for(lli i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}

signed main(){
    IOS
    solve();
    return 0;
}