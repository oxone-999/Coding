#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void dfs(vector<int> &vis,vector<int> adj[],int node,stack<int> &s){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(vis,adj,it,s);
        }
    }
    s.push(node);
}

void solve()
{
    int n;
    cin>>n;

    vector<int> adj[n+1];
    vector<vector<int>> B;
    int m = B.size();
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> vis(n+1);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(vis,adj,i,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}