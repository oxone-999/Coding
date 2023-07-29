//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct node{
    int area;
    pair<int,int> p1;
    pair<int,int> p2;
    node(pair<int,int> a, pair<int,int> b){
        p1 = a;
        p2 = b;
    }
};

void solve()
{
    priority_queue<node> pq;
    int n,m,q;
    cin>>n>>m>>q;

    while(q--){
        char c;
        cin>>c;
        int x;
        cin>>x;

        
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}