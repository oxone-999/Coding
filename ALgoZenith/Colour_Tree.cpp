//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli N = 100005;

vector<lli> parent[N];

void dfs(vector<lli> adj[],vector<lli> &vis,lli node,lli par){
    vis[node] = 1;

    for(auto it:adj[node]){
        if(vis[it] == -1){
            dfs(adj,vis,it,node);
        }
    }
}

void solve()
{
    lli n;
    cin>>n;

    vector<lli> adj[n+1];

    for(lli i=0;i<n-1;i++){
        lli u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    lli mx = 0;

    for(lli i=1;i<=n;i++){
        if(mx < adj[i].size()){
            mx = adj[i].size();
        }
    }

    cout<<mx+1<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}