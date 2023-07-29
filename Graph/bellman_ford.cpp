#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct Node{
    int u = 0,v = 0,wt = 0;
    Node(int x,int y,int z) : u(x), v(y), wt(z) {}
};

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<Node> edges;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        Node node = {u,v,w};
        edges.push_back(node);
    }

    int src;
    cin>>src;

    vector<int> dist(n+1,1e9);

    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            if(dist[it.u] + it.wt < dist[it.v]){
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    int fl = 0;
    for(auto it:edges){
        if(dist[it.u] + it.wt < dist[it.v]){
            cout<<"Negative Cycle";
            fl = 1;
            break;
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}