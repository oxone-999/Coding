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

const int N = 1000001;
int fact[N];
int factinv[N];
int pow2[N];

void init(){
    fact[0] = 1;
    factinv[0] = 1;
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
    lli n,a,b,c;
    cin>>n>>a>>b>>c;

    lli x = mul(fact[n],factinv[a]);
    lli y = mul(factinv[b],factinv[c]);

    cout<<mul(x,y)%mod<<endl;
}

signed main(){
    IOS
    init();
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}