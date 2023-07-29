//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n,x;
    cin>>n>>x;

    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    sort(vec.begin(),vec.end());
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        int target = x-vec[i];
        if(target <= 0) break;

        int ind = upper_bound(vec.begin()+i+1,vec.end(),target) - vec.begin();
        // cout<<ind<<" "<<i<<" ";
        // cout<<ind-i-1<<" "<<endl;
        cnt += ind-i-1;
    }
    cout<<cnt*2<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}