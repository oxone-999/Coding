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
        lli u,v;
        cin>>u>>v;

        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }

    lli dist[n+1];

    for(lli i=1;i<=n;i++){
        dist[i] = 1e18;
    }

    dist[1] = 0;

    deque<lli> d;
    d.push_back(1);

    while(!d.empty()){
        lli node = d.front();
        d.pop_front();

        for(auto it:adj[node]){
            lli v = it.first;
            lli w = it.second;

            if(dist[v] > dist[node] + w){
                dist[v] = dist[node] + w;
                if(w == 0){
                    d.push_front(v);
                }else d.push_back(v);
            }
        }
    }
    if(dist[n] == 1e18){
        cout<<(-1)<<endl;
    }else cout<<dist[n]<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}