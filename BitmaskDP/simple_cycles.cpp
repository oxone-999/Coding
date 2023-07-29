#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[21][1<<21];
int n;

int cycles(int node,int mask,int sz,int x,vector<vector<int>> &vec)
{
    if(dp[node][mask] != -1) return dp[node][mask];

    int ans = 0;

    if(sz > 2 && vec[node][x])
    {
        ans++;
    } 

    for(int j = x+1;j<n;j++){
        if((mask & (1<<j)) == 0 && vec[node][j]){
            ans += cycles(j,mask|(1<<j),sz+1,x,vec);
        }
    }
    return dp[node][mask] = ans;
}

void solve()
{
    int m;
    cin>>n>>m;

    memset(dp,-1,sizeof(dp));

    vector<int> adj[n+1];
    vector<vector<int>> vec(n+1,vector<int>(n+1,0));

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
        vec[u][v] = 1;
        vec[v][u] = 1;
    }

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += cycles(i,(1<<i),1,i,vec);
    }
    cout<<ans/2<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}