#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100100];

int dp[100100][2];
int vec[100100];

void indfs(int node,int par){
    dp[node][1] = vec[node];
    dp[node][0] = 0;

    for(auto it:adj[node])
    {
        if(it != par)
        {
            indfs(it,node);
            dp[node][1] += dp[it][0];
            dp[node][0] += max(dp[it][0],dp[it][1]);
        }
    }
}

void solve()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    indfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<endl;
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