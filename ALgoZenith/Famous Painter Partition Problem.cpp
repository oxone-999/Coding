//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(lli mid, lli k,vector<lli> &vec){
    lli n = vec.size();
    lli cnt = 1;
    lli x = 0;
    for(lli i=0;i<n;i++){
        x += vec[i];
        if(x > mid){
            cnt++;
            x = vec[i];
        }
        if(cnt > k) return 0;
    }
    return 1;
}

void solve()
{
    lli n,k;
    cin>>n>>k;

    lli mx = INT_MIN;
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
        mx = max(mx,it);
    }

    lli st = mx;
    lli en = 1e18;
    lli ans = 0;

    while(st<=en){
        lli mid = st + (en-st)/2;
        if(check(mid,k,vec)){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}