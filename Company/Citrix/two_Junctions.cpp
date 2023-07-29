#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int,int>> adj[700200];
int n; 

int shortestDist(int V,int distToV,int U){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e15);
    dist[V] = distToV;
    pq.push({distToV,V});

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        // cout<<distance<<" "<<prev << " " << dist[prev] << "\n";

        for(auto it:adj[prev]){
            // cerr << "+++" << "\n";
            int next = it.first;
            int nextDist = it.second;
            if(dist[next] > dist[prev] + nextDist){
                // cerr << next << " " << dist[next] << " " << dist[prev] + nextDist << "\n";
                dist[next] = dist[prev] + nextDist;
                pq.push({dist[next], next});
            }
        }
    }
    // cout << dist[U] << "\n";
    return dist[U];
}

void solve()
{
    int m;
    cin>>n>>m;

    // vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v,t;
        cin>>u>>v>>t;

        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }

    int X,Y;
    cin>>X>>Y;

    int distToX = shortestDist(1,0,X);
    int distXtoY = shortestDist(X,distToX,Y);
    int distYtoN = shortestDist(Y,distXtoY,n);

    // cout<<distToX<<" "<<distXtoY<<" "<<distYtoN;
    int ans = distYtoN;

    if(ans >= 1e14) cout<<(-1)<<endl;
    else cout<<ans<<endl;
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