//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

int par[200100];
int dep[200100];
vector<vector<int>> adj(200100);

void dfs(int node,int pp,int dp){
    par[node] = pp;
    dep[node] = dp;
    for(auto it:adj[node]){
        if(it != pp){
            dfs(it,node,dp+1);
        }
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0);

    int maxCh = 1;

    for(int i=2;i<=n;i++){
        if(dep[i] > dep[maxCh]){
            maxCh = i;
        }
    }
    dfs(maxCh,0,0);

    for(int i=1;i<=n;i++){
        if(dep[i] > dep[maxCh]){
            maxCh = i;
        }
    }
    int maxDep = dep[maxCh];

    int D = 0;
    if(maxDep % 2 == 0){
        D = maxDep/2;
    }else{
        cout<<(-1)<<endl;
        return;
    }
    int ans = maxCh;
    while(D--){
        ans = par[ans];
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}