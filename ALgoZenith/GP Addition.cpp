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
    lli n,q,k;
    cin>>n>>q>>k;

    map<lli,lli> mp1;
    map<lli,lli> mp2;

    for(lli i=0;i<q;i++){
        lli a,l,r;
        cin>>a>>l>>r;

        mp1[l] += mul(a,neg_pow(k,-l));
        mp2[r] += mul(a,neg_pow(k,-l));
    } 

    lli x = 0;
    for(lli i=1;i<=n;i++){
        x += mp1[i];
        x %= mod;
        if(x < 0) x += mod;
        else if(x >= mod) x -= mod;
        lli ans = mul(binpow(k,i),x);
        if(ans < 0) ans += mod;
        else if(ans >= mod) ans -= mod;
        cout<<ans<<" ";
        x -= mp2[i];
        x %= mod;
        if(x < 0) x += mod;
        else if(x >= mod) x -= mod;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}