//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    lli n;
    cin>>n;

    vector<vector<lli>> dist(n+1,vector<lli>(n+1,0));

    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }

    vector<lli> vec;
    for(lli i=1;i<=n;i++){
        lli x;
        cin>>x;
        vec.push_back(x);
    }
    reverse(all(vec));

    vector<lli> v;

    for(lli k=0;k<n;k++){
        for(lli i=1;i<=n;i++){
            for(lli j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][vec[k]] + dist[vec[k]][j]);
            }
        }

        lli ans  = 0;

        for(lli i=0;i<=k;i++){
            for(lli j=0;j<=k;j++){
                ans += dist[vec[i]][vec[j]];
            }
        }

        v.push_back(ans);
    }

    reverse(all(v));

    for(auto it:v){
        cout<<it<<" ";
    }
}

signed main(){
    IOS
    solve();
    return 0;
}