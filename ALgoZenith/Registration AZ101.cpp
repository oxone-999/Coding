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

    map<string,lli> mp;
    while(n--){
        string s;
        cin>>s;
        if(mp.count(s)){
            cout<<s<<mp[s]<<endl;
        }else cout<<"OK"<<endl;
        mp[s]++;
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}