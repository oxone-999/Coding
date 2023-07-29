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
    lli n,q;
    cin>>n>>q;

    map<lli,pair<lli,lli>> mp1;
    map<lli,pair<lli,lli>> mp2;
    map<lli,lli> mp3;
    map<lli,lli> mp4;

    lli a(0),b(0),c(0);

    for(lli i=0;i<q;i++){
        lli A,D,L,R;
        cin>>A>>D>>L>>R;
        lli x = mp1[L].first;
        lli y = mp1[L].second;
        mp1[L] = {x+A,y+D};
        lli z = mp2[R].first;
        lli w = mp2[R].second;
        mp2[R] = {z+A,w+D};
        mp3[L] += D*L;
        mp4[R] += D*L;
    }

    for(lli i=1;i<=n;i++){
        a += mp1[i].first;
        a %= mod;
        b += mp1[i].second;
        b %= mod;
        c += mp3[i];
        c %= mod;
        lli ans = a + b*i - c;
        ans %= mod;
        if(ans < 0) ans += mod;
        else if(ans >= mod) ans -= mod;
        cout<<ans<<" ";
        a -= mp2[i].first;
        a %= mod;
        b -= mp2[i].second;
        b %= mod;
        c -= mp4[i];
        c %= mod;
        if(a < 0) a += mod;
        if(b < 0) b += mod;
        if(c < 0) c += mod;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}