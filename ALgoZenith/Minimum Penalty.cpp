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

    lli i=0;
    lli j=0;

    unordered_map<lli,lli> mp;
    lli ans = LLONG_MAX;
    lli ind = 0;

    while(j<n){
        mp[vec[j]]++;
        if(j-i+1 == k){
            if(ans > mp.size()){
                ans = mp.size();
                ind = i;
            }
            mp[vec[i]]--;
            if(mp[vec[i]] == 0) mp.erase(vec[i]);
            i++;
        }
        j++;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}