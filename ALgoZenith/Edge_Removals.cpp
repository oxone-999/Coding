//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

int par[100100];
int Size[100100];
int cnt = 0;

void init(int n){
    for(int i=0;i<=100000;i++){
        par[i] = i;
        Size[i] = 0;
    }
    cnt = n;
}

int find(int x){
    if(par[x] == x) return x;
    else return (par[x] = find(par[x]));
}

void unite(int x,int y){
    int rootx = find(x);
    int rooty = find(y);
    if(Size[x] < Size[y]) swap(x,y);
    Size[x] += Size[y];
    par[rooty] = rootx;
    if(rootx != rooty) cnt--;
}

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;

    init(n);
    vector<pair<int,int>> edges;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    vector<pair<int,int>> vec(q);
    vector<int> marked(m,0);

    for(int i=0;i<q;i++){
        int ch;
        cin>>ch;

        if(ch == 1){
            int x;
            cin>>x;
            x--;
            vec[i] = {ch,x};
            marked[x] = true;
        }else {
            vec[i] = {ch,-1};
        }
    }

    for(int i=0;i<m;i++){
        if(!marked[i]){
            int u = edges[i].first;
            int v = edges[i].second;
            unite(u,v);
        }
    }   

    vector<int> ans;

    for(int i=q-1;i>=0;i--){
        if(vec[i].first == 1){
            int u = edges[vec[i].second].first;
            int v = edges[vec[i].second].second;
            unite(u,v);
        }else{
            ans.push_back(cnt);
        }
    }
    reverse(all(ans));

    for(auto it:ans){
        cout<<it<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}