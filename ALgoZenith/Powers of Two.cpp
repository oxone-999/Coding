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
    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    map<lli,lli> mp;

    for(lli i=0;i<n;i++){
        mp[vec[i]]++;
    }

    vector<lli> power(32,1);
    for(lli i=1;i<=31;i++){
        power[i] = power[i-1]*2;
    }
    lli cnt = 0;
    for(lli i=0;i<n-1;i++){
        mp[vec[i]]--;
        if(mp[vec[i]] == 0) mp.erase(vec[i]);
        for(lli j=0;j<=31;j++){
            if(mp.count(power[j]-vec[i])){
                cnt += mp[power[j]-vec[i]];
            }
        }
    }
    cout<<cnt<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}