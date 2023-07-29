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
    int n,k;
    cin>>n>>k;

    int cnt = 0;

    for(int i=0;i<k;i++){
        int ch,x,y;
        cin>>ch>>x>>y;

        if(ch == 1){
            if(x > n || y > n || x == y){
                cnt++;
            }
            else{
                unite(x,y);
            }
        }else {

        }
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}