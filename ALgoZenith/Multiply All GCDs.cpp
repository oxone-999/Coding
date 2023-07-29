//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli N = 100010;

lli binpow(int a, int b, int M) {
    if(!b) return 1;
    int temp = binpow(a, b / 2, M);
    temp = 1LL * temp * temp % M;
    if(b % 2) temp = 1LL * temp * a % M;
    return temp;
}

void solve()
{
    lli n;
    cin>>n;

    vector<lli> vec(n,0);
    unordered_map<lli,lli> mp;

    for(auto &it:vec){
        cin>>it;
        mp[it]++;
    }

    // pr(mp);

    vector<lli> f(N,0);

    for(lli i=2;i<N;i++){
        for(lli j=i;j<N;j+=i){
            if(mp.count(j)) f[i] += mp[j]; 
        }
        f[i] %= mod;
    }

    vector<lli> S1(N,0);

    for(lli i=N-1;i>0;i--){
        S1[i] = binpow(2, f[i], mod - 1) - 1;
        if(S1[i] < 0) S1[i] += mod - 1;
        for(int j = i + i; j < N; j += i) {
            S1[i] = (S1[i] - S1[j] + (mod - 1)) % (mod - 1);
        }
    }
    lli ans = 1;
    for(int i = 1; i < N; i++) {
        ans *= binpow(i, S1[i], mod) % mod;
    }
    cout << ans << endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}