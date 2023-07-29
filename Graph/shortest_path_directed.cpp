#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &s){
    vis[node] = 1;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,s);
        }
    }
    s.push(node);
}

void solve()
{
    int n;
    cin>>n;
    int src;
    cin>>src;

    vector<int> adj[n+1];
    vector<vector<int>> B;
    int m = B.size();
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    stack<int> s;
    vector<int> vis(n+1,0);

    dfs(src,vis,adj,s);

    vector<int> dist(n+1,1e9);
    dist[src] = 0;

    while(!s.empty()){
        int node = s.top();
        s.pop();

        if(dist[node] != 1e9){
            for(auto it:adj[node]){
                if(dist[it] > dist[node]+1){
                    dist[it] = dist[node] + 1;
                }
            }
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}