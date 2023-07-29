#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100100];

int sz[100100];
int indp[100100];
int outdp[100100];

void indfs(int node,int par){
    indp[node] = 0;
    sz[node] = 1;

    for(auto it:adj[node])
    {
        if(it != par)
        {
            indfs(it,node);
            sz[node] += sz[it];
            indp[node] += indp[it] + sz[it];
        }
    }
}

void outdfs(int node,int par){
    if(node == 1){
        outdp[node] = 0;
    }else{
        outdp[node] = outdp[par] + indp[par] - (indp[node] + sz[node]) + (n - sz[node]);
    }
    for(auto it:adj[node]){
        if(it != par){
            outdfs(it,node);
        }
    }
}

void solve()
{
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    indfs(1,0);
    outdfs(1,0);
    for(int i=1;i<i<=n;i++){
        cout<<indp[i] + outdp[i]<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}