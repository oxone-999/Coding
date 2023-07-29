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
    //Lucas Theorem

    lli n;
    cin>>n;

    lli ans = 1;

    for(int i=0;i<64;i++){
        if((n>>i) & 1) ans *= 2;
    }

    cout<<(n+1-ans)<<" "<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}