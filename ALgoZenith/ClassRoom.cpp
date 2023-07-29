//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(lli mid ,vector<lli> &vec, lli n, lli k){
    lli x = vec[0];
    k--;
    for(lli i=1;i<n;i++){
        if(vec[i] - x >= mid){
            x = vec[i];
            k--;
            if(k == 0) return 1;
        }
    }
    return 0;
}

void solve()
{
    lli n,k;
    cin>>n>>k;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    sort(all(vec));

    lli ans = 0;

    lli st = 0;
    lli en = 1e9;

    while(st<=en){
        lli mid = st + (en - st)/2;
        if(check(mid,vec,n,k)){
            ans = mid;
            st = mid+1;
        }else en = mid-1;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}