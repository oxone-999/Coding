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

    map<lli,lli> mp1;
    map<lli,lli> mp2;

    set<lli> s;

    for(lli i=0;i<n;i++){
        lli x,y;
        cin>>x>>y;

        s.insert(x);
        s.insert(y);

        mp1[x]++;
        mp2[y]++;
    }

    vector<lli> vec(all(s));

    lli ans = 0;

    lli x = 0;
    for(int i=0;i<vec.size();i++){
        x += mp1[vec[i]];
        if(x > 0) ans++;
        x -= mp2[vec[i]];
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}