//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

void solve()
{
    lli n;
    cin>>n;
    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    vector<lli> mx1(n,-1);
    for(lli i=1;i<n;i++){
        mx1[i] = max<lli>(mx1[i-1],vec[i-1]);
    }

    vector<lli> mx2(n,-1);
    for(lli i=n-2;i>=0;i--){
        mx2[i] = max<lli>(mx2[i+1],vec[i+1]);
    }

    // for(auto it:mx1) cerr<<it<<" ";
    // cerr<<endl;
    // for(auto it:mx2) cerr<<it<<" ";
    // cerr<<endl;

    lli ans = 0;
    for(lli i=0;i<n;i++){
        if(mx1[i] == -1 || mx2[i] == -1) continue; 
        lli x = min(mx1[i],mx2[i]);
        if(x > vec[i]) ans += (x-vec[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}