//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

lli add(lli a,lli b){
    lli ans = (a+b)%mod;
    if(ans<0) ans += mod;
    return ans;
}

lli sub(lli a,lli b){
    lli ans = (a-b)%mod;
    if(ans<0) ans += mod;
    return ans;
}

lli mul(lli a,lli b){
    lli ans = (a*b)%mod;
    if(ans<0) ans += mod;
    return ans;
}
lli binpow(lli a,lli b){
    if(b==0)return 1;
    if(b==1)return a;
    if((b%2)!=0){
        return mul(a,binpow(a,b-1));
    }else{
        lli temp = binpow(a,b/2);
        return mul(temp,temp);
    }
}

lli inv(lli a){
    return binpow(a,mod-2);
}

lli neg_pow(lli a,lli p){
    return binpow(a,mod-1+p);
}

lli div2(lli a,lli b){
    return mul(a,inv(b));
}

void solve()
{
    lli n,m;
    cin>>n>>m;
    lli i = 1;
    lli ans = 0;
    while(i <= n){
        lli r = n/(n/i);
        lli x = (r - i + 1)%mod;
        lli c = mul(x%mod,binpow((n/r)%mod,m)%mod);
        if(c < 0){
            while(c < 0){
                c += mod;
            }
        }
        c %= mod;
        ans += c;
        ans %= mod;
        i = r+1;
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}