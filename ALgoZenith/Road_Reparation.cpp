//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct Node{
    lli u,v,w;
};

lli par[100100];
lli Size[100100];
int cnt = 0;

void init(int n){
    for(lli i=0;i<=100000;i++){
        par[i] = i;
        Size[i] = 0;
    }
    cnt = n;
}

lli find(lli x){
    if(par[x] == x) return x;
    else return (par[x] = find(par[x]));
}

void unite(lli x,lli y){
    lli rootx = find(x);
    lli rooty = find(y);
    if(Size[x] < Size[y]) swap(x,y);
    Size[x] += Size[y];
    par[rooty] = rootx;
    if(rootx != rooty) cnt--;
}

void solve()
{
    lli n,m;
    cin>>n>>m;

    init(n);

    vector<Node> edges(m);
    for(lli i=0;i<m;i++){
        lli u,v,w;
        cin>>u>>v>>w;
        edges[i] = {u,v,w};
    }

    sort(all(edges),[](Node &a, Node &b){
        if(a.w == b.w){
            if(a.v == b.v) return a.u < b.u;
            else a.v < b.v;
        }return a.w < b.w;
    });

    lli ans = 0;

    for(lli i=0;i<m;i++){
        lli u = edges[i].u;
        lli v = edges[i].v;
        lli w = edges[i].w;

        if(find(u) != find(v)){
            unite(u,v);
            ans += w;
        }
    }
    if(cnt > 1){
        cout<<"IMPOSSIBLE"<<endl;
    }else cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}