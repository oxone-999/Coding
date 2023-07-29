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
    int n,m;
    cin>>n>>m;

    vector<vector<int>> vec(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            vec[i][j] = s[j]-'0';
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]) cnt++;
        }
    }
    int mx = INT_MIN;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            int x = vec[i][j] + vec[i][j+1] + vec[i+1][j] + vec[i+1][j+1];
            mx = max(4-x,mx);
        }
    }

    if(mx >= 2) cout<<cnt<<endl;
    else if(mx == 1) cout<<cnt-1<<endl;
    else cout<<cnt-2<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}