#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    int n,src;
    cin>>n>>src;
    int m;
    cin>>m;

    vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }   

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e9);

    dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();

        for(auto &it:adj[node]){
            int neigh = it.first;
            int weight = it.second;
            if(dist[neigh] > dist[node] + weight){
                dist[neigh] = dist[node] + weight;
                pq.push({dist[neigh],neigh});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}