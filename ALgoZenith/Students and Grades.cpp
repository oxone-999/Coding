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
    int n,m;
    cin>>n>>m;
    
    vector<int> vec(n,0);
    map<int,int> mp;
    for(auto &it:vec){
        cin>>it;
        mp[it]++;
    }

    vector<int> vec2(m,0);
    for(auto &it:vec2){
        cin>>it;
    }

    for(auto it:vec2){
        if(mp.count(it)){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
        mp[it]++;
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}