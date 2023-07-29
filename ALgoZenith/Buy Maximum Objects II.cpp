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
    lli n,q;
    cin>>n>>q;
    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }
    sort(all(vec));

    for(lli i=1;i<n;i++){
        vec[i] += vec[i-1];
    }

    for(lli i=0;i<q;i++){
        lli m;
        cin>>m;
        lli x = upper_bound(vec.begin(),vec.end(),m) - vec.begin();
        cout<<x<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}