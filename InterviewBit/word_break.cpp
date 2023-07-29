#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int wordBreak(string A, vector<string> &B) {
    bool dp[A.size()+1];
    memset(dp,false,sizeof(dp));
    dp[A.size()] = true;

    for(int i=A.size()-1;i>-1;i--)
    {
        for(auto it:B)
        {
            if(i+it.size() <= A.size() && A.substr(i,it.size()) == it) dp[i] = dp[i+it.size()];
            if(dp[i]) break;
        }
    }
    return dp[0];
}

void solve()
{
    
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}