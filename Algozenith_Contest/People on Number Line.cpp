//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
lli n,q;
vector<lli> vec;
map<lli,lli> mp;

bool check(lli mid){
    lli st = vec[0];
    while(n--){
        lli x = lower_bound(vec.begin(),vec.end(),st+mid) - vec.begin();
        if(x == 2*q) return 0;
        if(mp[vec[x]] < 1) st = st+mid;
        else st = vec[x];
        // cerr<<st<<endl;
    }
    return 1;
}

void solve()
{
    cin>>n>>q;

    for(lli i=0;i<q;i++){
        lli l,r;
        cin>>l>>r;

        mp[l]++;
        mp[r]--;
        vec.push_back(l);
        vec.push_back(r);
    }
    n--;

    sort(vec.begin(),vec.end());

    // cerr<<check(125000000000000000)<<endl;

    lli st = 1;
    lli en = 1e18;
    lli ans = 0;

    while(st <= en){
        lli mid = st + (en-st)/2;
        cout<<mid<<" "<<check(mid)<<endl;
        if(check(mid)){
            ans = mid;
            st = mid+1;
        }else en = mid-1;
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}