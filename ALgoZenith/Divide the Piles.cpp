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
    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }
    lli x = vec[0];
    for(auto it:vec){
        x = __gcd(it,x);
    }
    if(x == 1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}