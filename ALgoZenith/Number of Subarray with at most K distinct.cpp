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
    lli n,k;
    cin>>n>>k;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    if(k == 0){
        cout<<0<<endl;
        return;
    }

    lli i=0;
    lli j=0;
    lli ans = 0;
    map<lli,lli> mp;

    while(j < n){
        mp[vec[j]]++;
        if(mp.size() > k){
            while(mp.size() > k){
                mp[vec[i]]--;
                if(mp[vec[i]] == 0) mp.erase(vec[i]);
                ans += j-i-1;
                i++;
            }
        }
        j++;
    }
    while(i < j){
        ans += j-i-1;
        i++;
    }
    ans += n;
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}