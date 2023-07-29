#include<bits/stdc++.h>
using namespace std;

int count_dfs(int node,vector<int> adj[],vector<int> &vis){
    vis[node]=1;
    int count=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            count+=count_dfs(it,adj,vis);
        }
    }
    return count;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    vector<int> vis(n+1,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int count = count_dfs(i,adj,vis);
            ans += ceil(sqrt(count)); 
        }
    }
    cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}