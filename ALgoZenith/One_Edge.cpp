//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

lli dfs(vector<lli> adj[],vector<lli> &vis,lli node){
    vis[node] = 1;
    lli cnt = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            cnt += dfs(adj,vis,it);
        }
    }
    return cnt;
}

void solve()
{
    lli n,m;
    cin>>n>>m;

    vector<lli> adj[n+1];

    for(lli i=0;i<m;i++){
        lli u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<lli> vis(n+1,0);
    vector<lli> vec;
    for(lli i=1;i<=n;i++){
        if(!vis[i]){
            lli cnt = dfs(adj,vis,i);
            vec.push_back(cnt);
        }
    }

    lli sum = 0;

    for(lli i=0;i<vec.size();i++){
        sum += vec[i];
    }

    lli ans = 0;
    for(lli i=0;i<vec.size();i++){
        sum -= vec[i];
        ans += vec[i] * sum;
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}