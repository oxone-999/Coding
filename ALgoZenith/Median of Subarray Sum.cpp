//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(lli mid, vector<lli> &vec, lli n, lli m){
    lli sum = 0;
    lli k = mid;
    lli i = 0;
    lli j = 0;
    lli ans = 0;

    while(j < n){
        sum += vec[j];
        if(sum > k){
            while(sum > k){
                ans += j-i;
                if(ans >= m) return 1;
                sum -= vec[i];
                i++;
            }
        }
        j++;
    }
    while(i < n){
        ans += j-i;
        if(ans >= m) return 1;
        i++;
    }

    return 0;
}

void solve()
{
    lli n;
    cin>>n;

    vector<lli> vec(n,0);
    lli l = LLONG_MAX;
    lli r = 0;
    lli ans = 0;

    for(auto &it:vec){
        cin>>it;
        l = min(it,l);
        r += it;
    }

    lli m = n*(n+1)/2;

    while(l <= r){
        lli mid = l + (r-l)/2;
        if(check(mid,vec,n,(m+1)/2)){
            ans = mid;
            r = mid-1;
        }else l = mid+1;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}