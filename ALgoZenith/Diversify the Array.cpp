//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

void solve()
{
    lli n,k;
    cin>>n>>k;
    
    map<lli,lli> mp;
    vector<lli> vec(n,0);

    for(auto &it:vec){
        cin>>it;
        mp[it]++;
    }

    priority_queue<lli> pq;

    for(auto it:mp){
        pq.push(it.second);
    }

    while(!pq.empty() && pq.top() > 1 && k){
        lli x = pq.top();
        pq.pop();
        x--;
        k--;
        pq.push(x);
    }

    lli ans = (n*(n-1)/2);
    while(!pq.empty() && pq.top() > 1){
        lli x = pq.top();
        pq.pop();
        ans -= (x*(x-1)/2);
    } 
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}