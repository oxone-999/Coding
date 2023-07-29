#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int n,m;
vector<pair<int,int>> adj[200200];
int dist[200200];

void BFS01(int node){
    deque<int> dq;
    for(int i=0;i<=n;i++){
        dist[i] = 1e9;
    }
    dist[node] = 0;
    dq.push_back(node);
    while(!dq.empty()){
        int xx = dq.front();
        dq.pop_front();

        for(auto it:adj[xx]){
            int neigh = it.first;
            int weight = it.second;
            if(dist[neigh] > dist[xx] + weight){
                dist[neigh] = dist[xx] + weight;

                if(weight == 0){
                    dq.push_front(neigh);
                }else{
                    dq.push_back(neigh);
                }
            }
        }
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int sc;
    cin>>sc;

    BFS01(sc);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}