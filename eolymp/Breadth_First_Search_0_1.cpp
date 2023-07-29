#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int bfs(vector<vector<pair<int,int>>> adj,int n,int src,int dest){
    deque<int> q;
    vector<int> dist(n+1);
    for(int i=0;i<=n;i++){
        dist[i] = 1e9+7;
    }

    dist[src] = 0;
    q.push_back(src);

    while(!q.empty()){
        int node = q.front();
        q.pop_front();

        for(auto it:adj[node]){
            int neigh = it.first;
            int weight = it.second;
            if(weight == 1 && dist[node] + 1 < dist[neigh]){
                dist[neigh] = dist[node] + 1;
                q.push_back(neigh);
            } 
            else if(weight == 0 && dist[node] < dist[neigh]){
                dist[neigh] = dist[node];
                q.push_front(neigh);
            }
        }
    }
    return dist[dest];
}

void solve()
{
    int n,q,s,d;
    cin>>n>>q>>s>>d;

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<q;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    int ans = bfs(adj,n,s,d);
    cout<<ans;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}