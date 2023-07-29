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
    set<pair<lli,lli>> st;

    for(lli i=0;i<n;i++){
        lli l,r;
        cin>>l>>r;
        st.insert({l,r});
    }

    lli ans = 0;
    lli str = (*st.begin()).first-1;

    for(auto it:st){
        if(str < it.first){
            ans += it.second-it.first+1;
            str = it.second;
        }else if(str < it.second){
            ans += it.second - str;
            str = it.second;
        }   
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}