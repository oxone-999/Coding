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
    int n,k;
    cin>>n>>k;
    
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }
    sort(all(vec));
    int i = 0;
    for(i=0;i<n;i++){
        k -= vec[i];
        if(k < 0) break;
    }
    cout<<i<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}