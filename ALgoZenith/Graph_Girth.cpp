//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
int ans = INT_MAX;
int n,m;

void bfs(int i,vector<int> adj[]){
    int dist[n+1];
    for(int j=1;j<=n;j++){
        dist[j] = 1e9;
    }

    dist[i] = 0;
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            if(dist[it] == 1e9){
                q.push(it);
                dist[it] = dist[node] + 1;
            }
            else if(dist[node] <= dist[it]){
                ans = min(ans,dist[node] + dist[it] + 1);
                if(dist[node] == dist[it]){
                    return;
                }
            }
        }
    }
}

void solve()
{
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i=1;i<=n;i++){
        bfs(i,adj);
    }
    if(ans == INT_MAX) {
        cout<<(-1)<<endl;
        return;
    }
    else cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}