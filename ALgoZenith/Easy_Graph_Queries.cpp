//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

int dfs(vector<int> adj[], vector<int> &vis,int node,vector<int> &vec){
    vis[node] = 1;
    vec.push_back(node);
    int cnt = 1;

    for(auto it:adj[node]){
        if(!vis[it]){
            cnt += dfs(adj,vis,it,vec);
        }
    }
    return cnt;
}

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int,pair<int,int>> mp;

    vector<int> vis(n+1,0);

    int num = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> vec;
            int cnt = dfs(adj,vis,i,vec);
            for(auto it:vec){
                mp[it] = {cnt,num};
            }
            num++;
        }
    }

    for(int i=0;i<q;i++){
        int ch;
        cin>>ch;

        if(ch == 1){
            int x;
            cin>>x;
            cout<<mp[x].first<<endl;
        }else {
            int x,y;
            cin>>x>>y;
            if(mp[x].second == mp[y].second) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}