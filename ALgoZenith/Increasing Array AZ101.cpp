//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int ans = 0;
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }
    for(int i=1;i<n;i++){
        if(vec[i] >= vec[i-1]) continue;
        ans += vec[i-1]-vec[i];
        vec[i] = vec[i-1];
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}

