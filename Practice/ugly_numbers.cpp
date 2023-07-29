#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1510;
int dp[N];

void solve()
{
    int n;
    cin>>n;

    cout<<dp[n-1]<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int c2(0),c3(0),c5(0);
    dp[0] = 1;

    for(int i=1;i<1501;i++)
    {
        dp[i] = min({2*dp[c2],3*dp[c3],5*dp[c5]});
        if(dp[i] == 2*dp[c2]){
            c2++;
        }
        if(dp[i] == 3*dp[c3]){
            c3++;
        }
        if(dp[i] == 5*dp[c5]){
            c5++;
        }
    }

    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}