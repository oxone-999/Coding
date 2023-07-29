//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

lli gcd(lli a, lli b, lli& x, lli& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lli x1, y1;
    lli d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve()
{
    lli A,B,C,P;
    cin>>A>>B>>C>>P;
    
    lli g = __gcd(A,B);
    g = __gcd(g,C);
    lli n = P/C;

    lli ans = 0;
    lli x0,y0;
    lli g_dash = gcd(A,B,x0,y0);
    cout<<fixed<<setprecision(6);

    for(lli z=0;z<=n;z++){
        if((P-C*z) % g_dash != 0) continue;
        double h = (double)x0*(P-C*z)/B;
        double l = -((double)y0*(P-C*z)/A);
        lli hi = floor(h);
        lli lo = ceil(l);
        if(lo > hi) continue;
        ans += abs(hi - lo) + 1;
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli x = 1;
    lli t=1;cin>>t;while(t--){
        cout<<"Case "<<x<<": ";
        solve();
        x++;
    } 
    return 0;
}