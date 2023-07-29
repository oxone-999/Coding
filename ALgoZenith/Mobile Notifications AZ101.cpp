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
    int n,q;
    cin>>n>>q;

    map<int,int> mp;
    int ans = 0;

    for(int i=0;i<q;i++){
        int ch,x;
        cin>>ch>>x;
        if(ch == 1){
            mp[x]++;
            ans++;
        }else if(ch == 2){
            if(mp.count(x)) ans -= mp[x];
            mp.erase(x);
        }else{
            ans -= x;
        }
        cout<<ans<<endl;
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}