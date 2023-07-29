#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100100];

int dp[100100][20];

int dfs(int node,int gc,int pp){
    if(dp[node][gc] != -1)
        return dp[node][gc];

    int ans = 0;
    for(int col = 1;col<=m;col++)
    {
        int temp = 1;
        int cntch = 0;
        for(auto it:adj[node])
        {
            if(it != pp)
            {
                cntch++;
                temp *= dfs(it,__gcd(gc,col),node);
            }
        }
        if(cntch == 0){
            if(__gcd(gc,col) == 1)
                ans++;
        }
        else{
            ans += temp;
        }
    }
    return dp[node][gc] = ans;
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for(int i=1;i<=m;i++)
        ans += dfs(i,i,0);
    cout<<ans<<endl;
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