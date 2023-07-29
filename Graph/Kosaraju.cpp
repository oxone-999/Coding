#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &s){ // Strognly Connected Components
    vis[node] = 1;
    
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,s);
        }
    }
    s.push(node);
}

void dfs2(int node,vector<int> &vis,vector<int> adj[]){
    vis[node] = 1;
    
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs2(it,vis,adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	vector<int> adj[v+1];
    
    for(int i=0;i<edges.size();i++){
        int u,v;
        u = edges[i][0];
        v = edges[i][1];
        adj[u].push_back(v);
    }
    stack<int> s;
    vector<int> vis(v+1,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,adj,s);
        }
    }
    vector<int> topo;
    while(!s.empty()){
        topo.push_back(s.top());
        s.pop();
    }
    
    for(int i=0;i<v;i++){
        adj[i].clear();
    }
    
    for(int i=0;i<edges.size();i++){
        int u,v;
        v = edges[i][0];
        u = edges[i][1];
        adj[u].push_back(v);
    }
    
    vis.assign(v+1,0);
    int cnt = 0;
    for(int i=0;i<topo.size();i++){
        if(!vis[topo[i]]){
            dfs2(topo[i],vis,adj);
            cnt++;
        }
    }
    return cnt;
}


void solve()
{
    
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}