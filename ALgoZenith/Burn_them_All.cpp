//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct Node{
    lli u, v, w;
    Node(lli x,lli y, lli z){
        u = x;
        v = y;
        w = z;
    }
};

int par[404][404];

void printPath(int i, int j){
    if(i != j) printPath(i,par[i][j]);
}

void solve()
{
    lli n,m;
    cin>>n>>m;

    vector<pair<lli,lli>> adj[n+1];
    vector<Node> edges;

    for(lli i=0;i<m;i++){
        lli u,v;
        lli w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }

    vector<lli> dist(n+1,1e18);

    lli src;
    cin>>src;

    dist[src] = 0;

    priority_queue<pair<lli,lli>, vector<pair<lli,lli>>, greater<pair<lli,lli>>> pq;

    pq.push({dist[src], src});

    while(!pq.empty()){
        pair<lli,lli> x = pq.top();
        pq.pop();

        lli node = x.second;
        lli dis = x.first;

        if(dis > dist[node]) continue;

        for(auto it:adj[node]){
            lli v = it.first;
            lli w = it.second;

            if(dist[v] > dist[node] + w){
                dist[v] = dist[node] + w;
                pq.push({dist[v], v});
            }
        }
    }

    lli ans = 0;
    
    for(auto it:edges){
        lli u = it.u;
        lli v = it.v;
        lli w = it.w;

        ans = max(ans,(dist[u] + dist[v] + w) * 5);
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}


