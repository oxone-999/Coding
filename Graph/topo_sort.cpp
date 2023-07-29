#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void dfs(int node, vector<int> &vis, vector<int> adj[],stack<int> st){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}

void solve()
{
    int n;
    cin>>n;
                        
    vector<vector<int>> edges;
    int m = edges.size();
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  

    vector<int> vis(n+1,0);
    stack<int> st;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }                
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}