//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;

    int ar1 = (x2-x1)*(y2-y1);
    int ar2 = (a2-a1)*(b2-b1);

    if(a1 >= x2 || b1 >= y2 || a2 <= x1 || b2 <= y1) cout<<0<<" "<<ar1+ar2<<endl;
    else{
        int ans = (min(a2,x2) - max(a1,x1))*(min(b2,y2) - max(b1,y1));
        cout<<ans<<" "<<ar1+ar2-ans<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}