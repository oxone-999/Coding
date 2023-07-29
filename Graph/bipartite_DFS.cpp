#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

bool dfs(int node,vector<int> &col, vector<int> adj[]){
    for(auto it:adj[node]){
        if(col[it] == -1){
            col[it] = 1 - col[node];
            if(!dfs(it,col,adj)) return false;
        }else if(col[it] == col[node]) return false;
    }
    return true;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u,v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cin>>src;

    vector<int> col(n+1,-1);
    for(int i=1;i<=n;i++){
        if(col[i] == -1){
            col[i] = 0;
            if(!dfs(i,col,adj)){
                cout<<"Not Bipartite"<<endl;
                return;
            }
        }
    }
    cout<<"Bipartite"<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}