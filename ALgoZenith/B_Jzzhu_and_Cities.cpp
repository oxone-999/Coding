// Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct Node{
    lli node,weight,type;
    Node(lli n,lli w, lli t){
        node = n;
        weight = w;
        type = t;
    }
};

struct Node2{
    lli dist,node,type;
    Node2(lli d,lli n,lli t){
        dist = d;
        node = n;
        type = t;
    }

    bool operator>(const Node2& other) const {
        return dist > other.dist;
    }
};

void solve()
{
    lli n,m,k;
    cin>>n>>m>>k;

    vector<Node> adj[n+1];

    for(lli i=0;i<m;i++){
        lli u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w,0});
    }

    for(lli i=0;i<k;i++){
        lli s,w;
        cin>>s>>w;

        adj[1].push_back({s,w,-1});
    }

    lli dist[n+1];
    lli ans = 0;

    dist[1] = 0;

    priority_queue<Node2, vector<Node2>, greater<Node2>> pq;

    pq.push({dist[1],1,0});

    while(!pq.empty()){
        Node2 x = pq.top();
        pq.pop();

        lli u = x.node;
        lli dis = x.dist;
        lli type = x.type;

        if(dis > dist[u]) continue;

        for(auto it:adj[u]){
            lli v = it.node;
            lli w = it.weight;
            lli t = it.type;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v,t});
            }
        }

        ans += type;
    }

    cout<<(k + ans)<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}
