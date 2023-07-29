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

    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    sort(all(vec));

    int ans = 0;

    for(auto it:vec){
        if(it % 2 == 0){
            ans++;
        }
        else ans--;
    }

    if(ans == n || ans == -n){
        cout<<"YES"<<endl;
        return;
    }

    if(vec[0] % 2 == 0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}