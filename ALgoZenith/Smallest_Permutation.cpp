//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int> indegree(n+1,0);
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    priority_queue<int ,vector<int> , greater<int>> q;

    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> vec;
    while(!q.empty()){
        int node = q.top();
        q.pop();

        vec.push_back(node);

        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(vec.size() < n){
        cout<<(-1)<<endl;
        return;
    }

    for(auto it:vec){
        cout<<it<<" ";
    }
}

signed main(){
    IOS
    solve();
    return 0;
}