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
const lli N = 10001000;

void solve()
{
    lli n;
    cin>>n;

    vector<lli> prime(N,0);

    for(lli i=0;i<N;i++){
        prime[i] = i;
    }

    for(lli i=2;i<N;i++){
        if(prime[i] == i){
            for(lli j=i*i;j<N;j+=i){
                prime[j] = i;
            }
        }
    }
    map<lli,lli> mp;

    lli m;
    cin>>m;

    map<lli,lli> mp2;

    for(lli j=0;j<m;j++){
        lli x;
        cin>>x;
        
        while(prime[x] != x){
            mp2[prime[x]]++;    
            x /= prime[x];
        }
        if(x > 1){
            mp2[prime[x]]++;
        }
    }
    mp = mp2;
    // pr(mp);

    for(lli i=1;i<n;i++){
        lli m;
        cin>>m;

        map<lli,lli> mp2;

        for(lli j=0;j<m;j++){
            lli x;
            cin>>x;
            
            while(prime[x] != x){
                mp2[prime[x]]++;    
                x /= prime[x];
            }
            if(x > 1){
                mp2[prime[x]]++;
            }
        }
        for(auto &it:mp){
            mp[it.first] = min(mp2[it.first],it.second);
        }
    }
    lli ans = 1;

    for(auto it:mp){
        ans = mul(ans%mod,binpow(it.first%mod,it.second%mod));
    }

    cout<<ans%mod<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}