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
    map<lli,lli> mp;
    for(auto &it:vec){
        cin>>it;
        mp[it]++;
    }

    lli cnt = 0;
    for(lli i=0;i<n;i++){
        mp[vec[i]]--;
        cnt += mp[k+vec[i]] + mp[vec[i]-k];
        mp[vec[i]]++;
    }
    cout<<cnt/2<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}