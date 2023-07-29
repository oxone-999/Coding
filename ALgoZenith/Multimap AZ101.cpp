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
    
    multimap<string,int> mp;
    while(n--){
        string s;
        cin>>s;

        if(s == "add"){
            string x;
            int y;
            cin>>x>>y;
            mp.insert({x,y});
        }else if(s == "erase"){
            string x;
            cin>>x;
            auto it = mp.find(x);
            if(mp.count(x)) mp.erase(it);
        }else if(s == "eraseall"){
            string x;
            cin>>x;
            if(mp.count(x)) mp.erase(x);
        }else if(s == "print"){
            string x;
            cin>>x;
            auto it = mp.lower_bound(x);
            if(mp.count(x)) cout<<it->second<<endl;
            else cout<<0<<endl;
        }
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}