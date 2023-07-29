#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int vec[17][17];
int dp[20][(1<<16)];

int DAG(int pos,int mask)
{
    if(pos == n) return 0;

    if(dp[pos][mask] != -1) return dp[pos][mask];

    int ans = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if((mask & (1<<i)) == 0)
        {
            int cost = 0;
            for(int j=0;j<n;j++)
            {
                if(mask & (1<<j) &&  (i != j)) cost += vec[i][j];
            }
            ans = min(ans,DAG(pos+1,mask|(1<<i)) + cost);
        }
    }
    return dp[pos][mask] = ans;
}

void solve()
{
    cin>>n;

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    cout<<DAG(0,0)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}