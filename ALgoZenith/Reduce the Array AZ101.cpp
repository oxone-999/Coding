//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    lli n;
    cin>>n;
    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    priority_queue<lli,vector<lli>,greater<lli>> pq;

    for(auto it:vec){
        pq.push(it);
    }
    lli ans = 0;
    while(pq.size() > 1){
        lli x = pq.top();
        pq.pop();
        lli y = pq.top();
        pq.pop();
        ans += x+y;
        pq.push(x+y);
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}