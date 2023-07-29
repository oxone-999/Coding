//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool dfs(vector<int> adj[], vector<int> &vis,int node,int par){
    vis[node] = 1;

    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(adj,vis,it,node)) return true;
        }else if(it != par){
            return true;
        }
    }
    return false;
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

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(adj,vis,i,-1)){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}