//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(lli mid, vector<lli> &vec, lli n, lli k){
    unordered_map<lli,lli> mp;
    lli i=0;
    lli j=0;

    while(j < n){
        mp[vec[j]]++;
        if(j-i+1 == mid){
            if(mp.size() == k) return 1;
            mp[vec[i]]--;
            if(mp[vec[i]] == 0) mp.erase(vec[i]);
            i++;
        }
        j++;
    }
    return 0;
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

    lli k = mp.size();
    // cout<<k<<endl;

    lli st = 0;
    lli en = n;
    lli ans = LLONG_MAX;

    while(st <= en){
        lli mid = st + (en-st)/2;
        if(check(mid,vec,n,k)){
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