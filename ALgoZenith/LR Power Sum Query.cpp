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

lli div(lli a,lli b){
    return mul(a,inv(b));
}

void solve()
{
    int n,q,k;
    cin>>n>>q>>k;
    
    vector<lli> vec(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }

    vector<lli> pre1(n+1,0);

    for(int i=1;i<=n;i++){
        pre1[i] = ((vec[i]%mod)*(binpow(k,i)%mod))%mod;
    }

    for(int i=1;i<=n;i++){
        pre1[i] += pre1[i-1];
        pre1[i] %= mod;
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;

        lli ans = (((pre1[r]-pre1[l-1])%mod)*(neg_pow(k,-l)%mod))%mod;
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