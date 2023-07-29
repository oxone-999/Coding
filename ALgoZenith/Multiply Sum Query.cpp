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
    int n,q;
    cin>>n>>q;
    
    vector<lli> vec(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }

    vector<lli> pre1(n+1,0);
    vector<lli> pre2(n+1,0);

    for(int i=1;i<=n;i++){
        pre1[i] = (vec[i]*i)%mod;
    }

    for(int i=1;i<=n;i++){
        pre1[i] += pre1[i-1];
        pre1[i] %= mod;
    }

    for(int i=1;i<=n;i++){
        pre2[i] = vec[i];
    }

    for(int i=1;i<=n;i++){
        pre2[i] += pre2[i-1];
        pre2[i] %= mod;
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;

        lli ans = ((pre1[r]-pre1[l-1])%mod + (1-l)*((pre2[r]-pre2[l-1])%mod))%mod;
        if(ans < 0) ans += mod;
        if(ans >= mod) ans -= mod;
        cout<<ans<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}