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
    lli st = 0;
    lli en = -1;

    lli ans = 0;
    lli cnt = 0;
    while(st < n){
        while(en+1 < n && cnt+(vec[en+1] == 0?1:0) <= k){
            en++;
            if(vec[en] == 0) cnt++;
        }

        ans = max(ans,en-st+1);

        if(en < st){
            st++;
            en = st-1;
        }else{
            if(vec[st] == 0) cnt--;
            st++;
        }
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}