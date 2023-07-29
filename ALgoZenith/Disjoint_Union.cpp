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

void init(){
    for(int i=0;i<=100000;i++){
        par[i] = i;
        Size[i] = 0;
    }
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
}

void solve()
{
    int n,q;
    cin>>n>>q;

    init();

    for(int i=0;i<q;i++){
        int com,x,y;
        cin>>com>>x>>y;

        if(com == 0){
            unite(x,y);
        }else {
            if(find(x) == find(y)){
                cout<<1<<endl;
            }else cout<<0<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}