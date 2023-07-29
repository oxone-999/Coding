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

signed main(){
    IOS
    
    while(true){
        lli n,d;
        cin>>n>>d;

        if(!n && !d) break;

        map<lli,lli> mp;

        for(lli i=2;i*i<=n;i+=2){
            if(n%i == 0){
                lli cnt = 0;
                while(n%i == 0){
                    cnt++;
                    n /= i;
                }
                if(cnt) mp[i] += 2*cnt;
            }
        }

        if(n > 1){
            mp[n] += 2;
        }

        mp[2] += 2*d;
        mp[5] += 2*d;

        lli ans = 1;
        bool sqr = true;

        for(auto it:mp){
            ans = mul(ans%mod,(it.second+1)%mod)%mod;
            ans += mod;
            ans %= mod;
            if(it.second % 2) sqr = false;
        }
        ans *= 2;
        ans += mod;
        ans %= mod;

        if(sqr) cout<<(ans-1+mod)%mod<<endl;
        else cout<<ans % mod<<endl;
    }

    return 0;
}