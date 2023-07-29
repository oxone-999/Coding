#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> adj[100100];
int dep[100100];
int par[100100];

void dfs(int node,int parent,int depth)
{
    dep[node] = depth;
    par[node] = parent;

    for(auto it:adj[node]){
        if(it != parent){
            dfs(it,node,depth+1);
        }
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

    int maxch = 1;
    for(int i=2;i<n;i++)
    {
        if(dep[i] > dep[maxch]){
            maxch = i;
        }
    }
    dfs(maxch,0,0);
    int diameter = INT_MIN;

    for(int i=1;i<n;i++)
    {
        diameter = max(dep[i],diameter);
    }
    cout<<diameter<<endl;

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