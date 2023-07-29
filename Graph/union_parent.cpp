#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int parent[100100];
int rankP[100100];

int findParent(int node)
{
    if(node == parent[node]) 
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionn(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if(rankP[u] < rankP[v])
        parent[u] = v;
    else if(rankP[u] > rankP[v]) parent[v] = u;
    else 
    {
        parent[v] = u;
        rankP[u]++;
    }
}

void solve()
{
    
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}