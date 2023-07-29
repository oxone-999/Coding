//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void dfs(vector<int> adj[],int node,vector<int> &vis){
    vis[node] = 1;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj,it,vis);
        }
    }
}

void solve()
{
    int n,m;

    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(adj,i,vis);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}