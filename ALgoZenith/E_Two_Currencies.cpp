//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct Node{
    lli node,A,B;
    Node(lli n,lli a,lli b){
        node = n;
        A = a;
        B = b;
    }
};

struct Node2{
    lli dist,node,silver;
    Node2(lli d,lli n,lli s){
        dist = d;
        node = n;
        silver = s;
    }

    bool operator>(const Node2& other) const {
        return dist > other.dist;
    }
};

void solve()
{
    lli n,m,s;
    cin>>n>>m>>s;

    vector<Node> adj[n+1];
    lli Amax = LLONG_MIN;

    for(lli i=0;i<m;i++){
        lli u,v,a,b;
        cin>>u>>v>>a>>b;
        adj[u].push_back({v,a,b});
        adj[v].push_back({u,a,b});
        Amax = max(Amax,a);
    }

    map<lli,pair<lli,lli>> mp;

    for(lli i=1;i<=n;i++){
        lli c,d;
        cin>>c>>d;
        mp[i] = {c,d};
    }

    lli dist[n+1];

    for(lli i=1;i<=n;i++){
        dist[i] = 1e18;
    }

    dist[1] = 0;

    priority_queue<Node2, vector<Node2>, greater<Node2>> pq;

    pq.push({dist[1],1,s});

    while(!pq.empty()){
        Node2 node = pq.top();
        pq.pop();

        lli dis = node.dist;
        lli u = node.node;
        lli s = node.silver;

        if(s < 0) continue;
        if(dis > dist[u]) continue;

        for(auto it:adj[u]){
            lli v = it.node;
            lli a = it.A;
            lli b = it.B;

            if(dist[v] > dist[u] + b){
                dist[v] = dist[u] + b;
                pq.push({dist[v],v,s-a});
            }
        }
        if(s <= Amax*(n-1)){
            dist[u] += mp[u].second;
            pq.push({dist[u],u,s+mp[u].first});
        }
    }

    for(lli i=2;i<=n;i++){
        cout<<dist[i]<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}