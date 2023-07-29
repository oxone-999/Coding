#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100100];

int indp[100100];
int outdp[100100];

int ans[100100];

void dfsin(int node,int par){
    indp[node] = 0;

    for(auto it:adj[node])
    {
        if(it != par)
        {
            dfsin(it,node);
            indp[node] = max(indp[it] + 1,indp[node]);
        }
    }
}

void dfsout(int node,int par,int outval){
    outdp[node] = outval;

    int max1 = -1,max2 = -1;
    for(auto it:adj[node])
    {
        if(it != par){
            if(indp[it] > max1){
                max2 = max1;
                max1 = indp[it];
            }else if(indp[it] > max2){
                max2 = indp[it];
            }
        }
    }

    for(auto it:adj[node]){
        if(it != par){
            if(indp[it] == max1){
                dfsout(it,node,max(max2+2,outdp[node]+1));
            }else{
                dfsout(it,node,max(max1+2,outdp[node]+1));
            }
        }
    }
}

void solve()
{
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsin(1,0);
    dfsout(1,0);
    for(int i=1;i<i<=n;i++){
        cout<<max(indp[i],outdp[i])<<" ";
    }
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