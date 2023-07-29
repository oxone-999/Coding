#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(auto &it:vec){
        cin>>it;
    }

    vector<int> dp(n,1);

    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<min(n,i+257);j++){
            if((vec[i]^j) < (vec[j]^i)){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}