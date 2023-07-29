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

    cout<<bitset<64>(n)<<endl;

    lli x = __builtin_clzll(n);
    lli y = __builtin_ctzll(n);

    if(n == 0) cout<<(-1)<<endl;
    else cout<<63-x<<endl;

    if(n == 0) cout<<(-1)<<endl;
    else cout<<y<<endl;

    if(n == 0) cout<<0<<endl;
    else {
        if((n & (n-1)) == 0 && n > 1) cout<<1<<endl;
        else cout<<0<<endl;
    }

    if(n == 0) cout<<(-1)<<endl;
    else cout<<(1LL<<y)<<endl;

    if(n == 0) cout<<2<<endl;
    else{
        if((n & (n-1)) == 0 && n > 1) cout<<(1LL<<((63-x)%63))<<endl;
        else cout<<(1LL<<((63-x+1)%63))<<endl;
    } 
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}