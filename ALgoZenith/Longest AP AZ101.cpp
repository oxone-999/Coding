//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    int x = vec[0];
    int d = INT_MAX;
    int ans = 0;
    int y = 1;
    for(int i=1;i<n;i++){
        if(d != vec[i]-vec[i-1]){
            d = vec[i]-vec[i-1];
            ans = max(ans,y);
            y = 1;
        }
        y++;
    }ans = max(ans,y);
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}