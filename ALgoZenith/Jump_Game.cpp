//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli N = 4e5+7;

void solve()
{
    lli n,a,b;
    cin>>n>>a>>b;

    lli m= n;

    vector<lli> vec(n,0);
    map<lli,vector<lli>> mp;
    for(lli i=0;i<n;i++){
        lli x;
        cin>>x;

        vec[i] = x;
        mp[x].push_back(i);
    }

    lli src;
    cin>>src;
    src--;

    vector<vector<pair<lli,lli>>> adj(N);
    for(lli i=0;i<n-1;i++){
        lli u = i;
        lli v = i+1;

        adj[u].push_back({v,b});
        adj[v].push_back({u,b});
    }
    n++;
    for(auto it:mp){
        vector<lli> v = it.second;
        for(auto itr:v){
            adj[itr].push_back({n,a});
            adj[n].push_back({itr,0});
        }
        n++;
    }

    lli dist[n+1];

    for(lli i=0;i<n;i++){
        dist[i] = 1e18;
    }

    dist[src] = 0;

    priority_queue<pair<lli,lli>, vector<pair<lli,lli>> , greater<pair<lli,lli>>> pq;

    pq.push({dist[src],src});

    while(!pq.empty()){
        lli node = pq.top().second;
        lli dis = pq.top().first;
        pq.pop();

        if(dis > dist[node]){
            continue;
        }

        for(auto it:adj[node]){
            lli v = it.first;
            lli w = it.second;

            if(dist[v] > dist[node] + w){
                dist[v] = dist[node] + w;
                pq.push({dist[v],v});
            }
        }
    }

    for(lli i=0;i<m;i++){
        cout<<dist[i]<<" ";
    }
}

signed main(){
    IOS
    solve();
    return 0;
}