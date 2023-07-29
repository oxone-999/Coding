//TOPO SORT ON DAG

#include<bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int node ,vector<int> &vis,stack<int> &s, vector<int> adj[])
{
    vis[node] = 1;

    for(auto it:adj[node]){
        if(!vis[it])
        {
            dfs(it,vis,s,adj);
        }
    }
    s.push(node);
}

void solve()
{
    int n,k;
    cin>>n>>k;

    vector<string> vec(n);
    for(auto &it:vec){
        cin>>it;
    }
    vector<int> adj[k+1];

    for(int i=0;i<n-1;i++)
    {
        int j = 0;
        int num = min(vec[i].size(),vec[i+1].size());
        
        while(j < num && vec[i][j] == vec[i+1][j])
        {
            j++;
        }
        if(j != num) adj[vec[i][j]-'a'].push_back(vec[i+1][j]-'a');
    }

    stack<int> s;

    vector<int> vis(k+1,0);

    for(int i=0;i<k;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,s,adj);
        }
    } 

    string str;
    while(!s.empty())
    {
        str.push_back(s.top()+'a');
        s.pop();
    }

    cout<<str<<endl;
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