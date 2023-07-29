#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> adj[200200];
int inTime[200200], loTime[200200];
int timer = 0;
vector<pair<int,int>> vec;

void dfs(int node,int parent)
{
    timer++;
    inTime[node] = loTime[node] = timer;

    for(auto it:adj[node]){
        if(it != parent){
            if(!inTime[it]){
                dfs(it,node);
                loTime[node] = min(loTime[node],loTime[it]);
                if(loTime[it] > inTime[node]){
                    vec.push_back({node,it});
                }
            }
            else{
                loTime[node] = min(loTime[node],loTime[it]);
            }
        }
    }
}

void solve()
{
    int n,k;
    cin>>n>>k;

    vec.clear();
    for(int i=0;i<k;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    sort(vec.begin(),vec.end());

    for(auto it:vec){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}