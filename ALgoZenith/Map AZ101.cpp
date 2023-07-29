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
    int n;
    cin>>n;

    map<string,int> mp;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        if(s == "add"){
            string x;
            int y;
            cin>>x>>y;
            mp[x] = y;
        }else if(s == "erase"){
            string x;cin>>x;
            if(mp.count(x)) mp.erase(x);
        }else{
            string x;cin>>x;
            cout<<mp[x]<<endl;
        }
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}