//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(lli mid, lli k,vector<lli> &vec){
    int n = vec.size();
    for(lli i=0;i<n-1;i++){
        lli diff = vec[i+1] - vec[i] - 1;
        k -= diff/mid;
        if(k < 0) return 0;
    }
    return 1;
}

void solve()
{
    lli n,k;
    cin>>n>>k;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    lli st = 1;
    lli en = 1e9;
    lli ans = 0;

    while(st<=en){
        lli mid = st + (en-st)/2;
        if(check(mid,k,vec)){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}