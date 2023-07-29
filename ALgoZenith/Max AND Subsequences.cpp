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

    lli ans = 0;

    for(lli i=62;i>=0;i--){
        vector<lli> v;
        lli cnt = 0;
        for(auto it:vec){
            if(it & (1<<i)){
                v.push_back(it);
                cnt++;
            }
        }
        if(cnt >= k){
            vec.clear();
            vec = v;
            ans |= (1<<i);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}