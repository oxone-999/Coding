//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    vector<int> A(n,0);
    vector<int> B(n,0);

    for(auto &it:A){
        cin>>it;
    }

    for(auto &it:B){
        cin>>it;
    }
    cout<<fixed<<setprecision(6);
    map<double,int> mp;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(A[i] == 0){
            if(B[i] == 0) cnt++;
            continue;
        }
        double d = (double)(-B[i])/(double)(A[i]);
        mp[d]++;
    }
    int ans = INT_MIN;
    for(auto it:mp){
        ans = max(ans,it.second);
    }
    cout<<ans+cnt<<endl;
}

signed main(){
    IOS
    int t=1;cin>>t;while(t--) solve();
    return 0;
}