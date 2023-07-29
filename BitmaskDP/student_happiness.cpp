#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int vec[51][20];

int dp[55][1<<11];

int happiness(int i,int mask){
    if(i == m) return 0;
	
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = happiness(i+1,mask);

    for(int j=0;j<n;j++){
        if((mask & (1<<j)) == 0) 
        {
            ans = max(ans,happiness(i+1,(mask|(1<<j)))+vec[i][j]);
        } 
    } 
    return dp[i][mask] = ans;
}

void solve()
{
    cin>>n>>m;

    memset(dp,-1,sizeof(dp));

    memset(vec,0,sizeof(vec));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    } 

    cout<<happiness(0,0)<<endl;
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