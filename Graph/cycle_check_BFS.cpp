#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u,v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cin>>src;

    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            queue<pair<int,int>> q;
            q.push({src,-1});
            vis[src] = 1;
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto it:adj[node]){
                    if(!vis[it]){
                        q.push({it,node});
                        vis[it] = 1;
                    }else{
                        if(it != parent){
                            cout<<"CYCLE PRESENT"<<endl;
                            return;
                        }
                    }
                }
            }
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}