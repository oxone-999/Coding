//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(lli mid, vector<lli> &v, lli n, lli k){
    lli ans = 0;    
    lli x = 0;
    for(auto it:v){
        if(it >= mid){
            ans++;
        }else{
            x += it;
        }
        if(ans >= k) return 1;
    }

    ans += x/mid;
    if(ans >= k) return 1;
    else return 0;
}

void solve()
{
    lli n,k;
    cin>>n>>k;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    map<lli,lli> mp;

    for(auto it:vec){
        mp[it]++;
    }
    vector<lli> v;
    for(auto it:mp){
        v.push_back(it.second);
    }

    sort(all(v),greater<lli>());

    if(mp.size() < k){
        cout<<0<<endl;
        return;
    }

    lli l = 0;
    lli r = n/k;
    lli ans = 0;

    while(l <= r){
        lli mid = l + (r-l)/2;
        if(check(mid,v,n,k)){
            ans = mid;
            l = mid+1;
        }else r = mid-1;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}