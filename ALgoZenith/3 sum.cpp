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
    lli n,sum;
    cin>>n>>sum;

    vector<lli> vec(n,0);

    for(auto &it:vec){
        cin>>it;
    }

    sort(all(vec));
    lli ans = LLONG_MAX;
    
    for(lli i=0;i<n-2;i++){
        lli target = sum-vec[i];

        lli j = i+1;
        lli k = n-1;
        while(j < k){
            ans = min(ans,abs(vec[j] + vec[k] - target));
            if(vec[j] + vec[k] < target){
                j++;
            }else if(vec[j] + vec[k] == target){
                cout<<0<<endl;
                return;
            }else k--;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}