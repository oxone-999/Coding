#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int longestValidParentheses(string A) {
    int n = A.length();
    int dp[n+1];
    dp[0] = 0;
    int ans = 0;
    for(int i=1; i<n; i++)
    {
        if(A[i]=='(')
            dp[i] = 0;
        else
        {
            if(A[i-1]=='(')
                dp[i] = 2+((i>2)?dp[i-2]:0);
            else
            {
                if(i-dp[i-1]-2>=0 && A[i-dp[i-1]-1]=='(')
                    dp[i] = dp[i-dp[i-1]-2]+dp[i-1]+2;
                else if(i-dp[i-1]-1>=0 && A[i-dp[i-1]-1]=='(')
                    dp[i] = dp[i-1]+2;
                else
                    dp[i] = 0;
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

void solve()
{
    string s;
    cin>>s;
    cout<<longestValidParentheses(s)<<endl;    
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}