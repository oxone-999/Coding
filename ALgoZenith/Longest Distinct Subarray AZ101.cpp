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

    lli i(0),j(0);
    lli ans = LLONG_MIN;
    unordered_map<lli,lli> mp;

    while(j<n){
        if(mp.count(vec[j])){
            ans = max(ans,j-i);
            while(mp.count(vec[j])){
                mp[vec[i]]--;
                if(mp[vec[i]] == 0) mp.erase(vec[i]);
                i++;
            }
        }
        mp[vec[j]]++;
        j++;
    }
    ans = max<lli>(ans,j-i);
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}