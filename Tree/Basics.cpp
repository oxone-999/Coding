#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> adj[100100];
int dep[100100];
int par[100100];
int subTreeSz[100100];
bool isleaf[100100];
int numChild[100100];

void dfs(int node,int parent,int depth)
{
    dep[node] = depth;
    par[node] = parent;

    subTreeSz[node] = 1;

    numChild[node] = 0;
    for(auto it:adj[node]){
        if(it != parent){
            numChild[it]++;
            dfs(it,node,depth+1);
            subTreeSz[node] += subTreeSz[v];
        }
    }
    if(numChild[node] == 0){
        isleaf[node] = 1;
    }
}

void solve()
{
    int n;
    
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);
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