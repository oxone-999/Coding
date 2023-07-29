// Find the longest increasing subsequence of a given array of integers, A.

// In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and 
// in which the subsequence is as long as possible. 

// This subsequence is not necessarily contiguous, or unique.

// In this case, we only care about the length of the longest increasing subsequence.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int LIS_dp(vector<int> &vec){ // Time Complexity : O(N^2)
    int n = vec.size();

    int dp[n+1];
    int Omx = 0;
    dp[0] = 1;
    
    for(int i=1;i<n;i++){
        int mx = 0;
        for(int j=0;j<i;j++){
            if(vec[i] > vec[j]) mx = max(dp[j],mx);
            dp[i] = mx+1;
        }
        Omx = max(Omx,dp[i]);
    }
    return Omx; 
}

int LIS_BS(vector<int> &vec){ // Time Complexity : O(NlogN)
    set<int> s;
    int n = vec.size();
    for(int i=0;i<n;i++){
        if(!s.empty() && vec[i] <= (*s.rbegin())){
            auto it = s.lower_bound(vec[i]);
            s.erase(it);
            s.insert(vec[i]);
        }
        else s.insert(vec[i]);
    }
    return s.size();
}

void solve()
{
    int n;
    cin>>n;

    vector<int> vec(n);
    for(auto &it:vec) cin>>it;
    
    cout<<LIS_dp(vec)<<endl;
    cout<<LIS_BS(vec)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}