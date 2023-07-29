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
    
    multiset<lli> s;

    for(lli i=0;i<n;i++){
        lli x;
        cin>>x;

        auto it = s.upper_bound(x);
        if(it != s.end()){
            s.erase(it);
        }
        s.insert(x);
    }
    cout<<s.size()<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}