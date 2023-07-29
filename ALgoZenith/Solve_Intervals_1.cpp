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
    lli n,l;
    cin>>n>>l;

    vector<pair<lli,lli>> lliervals(n);
    lli st = 0, en = 0;

    for(lli i=0;i<n;i++){
        lli l,r;
        cin>>l>>r;

        lliervals[i] = {l,r};
    }

    sort(all(lliervals));

    // pr(lliervals);

    lli c = 0;
    lli ans = 0;
    lli last = 0;

    for(lli i=0;i<n;i++){
        lli str = lliervals[i].first;
        lli edr = lliervals[i].second;
        if(str > c){
            c = last;
            ans++;
        }
        last = max(last,edr);
    }

    if(c != l){
        ans++;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}