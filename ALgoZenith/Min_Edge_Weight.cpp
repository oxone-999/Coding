//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli N = 100100;

lli par[N];
lli Size[N];

void init(){
    for(lli i=0;i<N;i++){
        par[i] = i;
        Size[i] = 1;
    }
}

lli find(lli x){
    if(par[x] == x) return x;
    else return (par[x] = find(par[x]));
}

void unite(lli rootx,lli rooty){
    if (rootx == rooty)
		return;
	if (Size[rootx] < Size[rooty]) swap(rootx,rooty);
    par[rooty] = rootx;
    Size[rootx] += Size[rooty];
}

void solve()
{
    lli n;
    cin>>n;

    init();

    vector<pair<lli,pair<lli,lli>>> edges;

    for(lli i=0;i<n-1;i++){
        lli u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }

    sort(all(edges));
    reverse(all(edges));

    lli res = 0;

    for(auto it:edges){
        lli u = it.second.first;
        lli v = it.second.second;
        lli w = it.first;

        u = find(u);
        v = find(v);

        res += Size[v]*Size[u]*w;

        unite(u,v);
    }
    cout<<res<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}