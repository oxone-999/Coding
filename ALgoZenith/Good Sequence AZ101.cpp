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
    int n;
    cin>>n;
    
    vector<int> vec(n,0);
    map<int,int> mp;
    for(auto &it:vec){
        cin>>it;
        mp[it]++;
    }
    lli ans = 0;
    for(auto it:mp){
        if(it.first < it.second) ans += (it.second-it.first);
        else if(it.first > it.second) ans += it.second;
    }cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}