//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool cycle(int node, vector<int> &vis, vector<set<int>> &adj, int par){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it] == 0){
            if(cycle(it,vis,adj,node)) return true;
        }else if(it != par){
            return true;
        } 
    }
    return false;
}

void solve()
{
    int n;
    cin>>n;

    vector<int> vec(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }

    vector<set<int>> adj(n+1);

    for(int i = 1;i<=n;i++){
        int u = i;
        int v = vec[i];

        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<int> vis(n+1,0);
    int fixed = 0;
    int open = 0;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycle(i,vis,adj,-1)) fixed++; 
            else open++;
        }
    }
    cout<<fixed + ((open)?1:0)<<" "<<fixed + open<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}