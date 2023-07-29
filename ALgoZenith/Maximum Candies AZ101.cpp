//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n,c;
    cin>>n>>c;
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    sort(vec.begin(),vec.end());
    int i=0;
    int ans = 0;
    while(c > 0){
        c -= vec[i++];
        if(c < 0) break;
        ans++;     
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}