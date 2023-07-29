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

    lli mx = 0;

    for(lli i=n-2;i>=0;i--){
        vec[i] ^= vec[i+1];
    }

    for(auto it:vec){
        mx = max(mx,it);
    }
    lli ans = 0;
    for(lli i=9;i>=0;i--){
        lli x = 0;
        for(lli j=0;j<n;j++){
            x = max(x,mx^vec[j]);
        }
        ans = max(ans,x);
        mx = mx ^ x;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}