//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli N = 200200;

vector<vector<lli>> g(N);
lli par[N];
lli sv[N];
lli n = 0;

lli ans = 1e9;

void dfs(lli node ,lli pp){
    par[node] = pp;
    sv[node] = 1;

    for(auto it:g[node]){
        if(it != pp){
            dfs(it, node);
            sv[node] += sv[it];
        }
    }
}

void dfs2(lli node ,lli pp){
    if(ans != 1e9) return;
    bool f = true;
    for(auto it:g[node]){
        if(it != pp){
            if(sv[it] > n/2){
                f = false;
                dfs2(it,node);
            }
        }
    }
    if(f){
        ans = node;
        return;
    }
}

void solve()
{
    cin>>n;

    vector<pair<lli,lli>> edges(n-1);

    for(lli i=0;i<n-1;i++){
        lli u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u,v};
    }

    dfs(1,0);
    dfs2(1,0);

    lli res = ans;
    ans = 1e9;

    dfs(n,0);
    dfs2(n,0);

    res = min(ans,res);

    cout<<res<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}