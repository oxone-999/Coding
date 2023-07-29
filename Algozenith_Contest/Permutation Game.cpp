//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli N = 1e5+5;

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

int fact[N];
int factinv[N];
int pow2[N];

void init(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = mul(fact[i-1],i);
    }

    pow2[0] = 1;
    for(int i=1;i<N;i++){
        pow2[i] = mul(pow2[i-1],2);
    }
    
    // O(n+log(mod))
    factinv[N-1] = inv(fact[N-1]);
    for(int i=N-2;i>=0;i--){
        factinv[i] = mul(factinv[i+1],i+1);
    }
}

int ncr(int n,int r){
    if(r<0||r>n)return 0;
    return mul(fact[n],mul(factinv[r],factinv[n-r]));
}

void solve()
{
    lli n;
    cin>>n;

    lli der[N] = {0};
 
    der[1] = 0;
    der[2] = 1;
 
    for (lli i = 3; i <= n; ++i){
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]);
        der[i] %= mod;
    }

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    vector<lli> pre(n+1,0);

    for(lli i=2;i<=n;i++){
        pre[i] += (pre[i-1] + der[i]*ncr(n,i))%mod;
    }

    lli q;
    cin>>q;

    while(q--){
        lli x;
        cin>>x;
        cout<<pre[x]+1<<endl;
    }
}

signed main(){
    IOS
    init();
    solve();
    return 0;
}