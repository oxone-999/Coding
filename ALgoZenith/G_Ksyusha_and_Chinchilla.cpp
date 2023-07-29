//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool ok;

int dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &ansl,map<pair<int,int>,int> &mp,int par){
    vis[node] = 1;

    if(ok == false) return 0;

    vector<int> v;

    for(auto it:adj[node]){
        if(!vis[it]){
            int x = dfs(it,vis,adj,ansl,mp,node);
            if(x) v.push_back(x);
        }
    }
    if(v.size() > 2){
        ok = false;
        return 0;
    }

    if(v.size() == 0) return 1;
    else if(v.size() == 1){
        if(v[0] == 2){
            ansl.push_back(mp[{node,par}]);
            return 0;
        }
        if(v[0] == 1) return 2;
        ok = false;
        return 0;
    }
    else if(v.size() == 2){
        if(v[0] == 1 && v[1] == 1){
            ansl.push_back(mp[{node,par}]);
            return 0;
        }
        ok = false;
        return 0;
    }
}

void solve()
{
    int n;
    cin>>n;

    vector<int> adj[n+1];
    map<pair<int,int>,int> mp;

    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;

        mp[{u,v}] = i;

        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}] = i;
        mp[{v,u}] = i;
    }
    vector<int> v(n+1,0);
    vector<int> ansl;

    if(n % 3 != 0){
        cout<<(-1)<<endl;
        return;
    }

    ok = true;
    dfs(1,v,adj,ansl,mp,0);

    if(ok == false){
        cout<<(-1)<<endl;
        return;
    }else{
        ansl.pop_back();
        cout<<ansl.size()<<endl;
        for(auto it:ansl){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}   

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}