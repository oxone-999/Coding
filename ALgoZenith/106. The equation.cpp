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
    lli a,b,c,x1,x2,y1,y2;
    cin>>a>>b>>c>>x1>>x2>>y1>>y2;

    lli x0,y0;
    lli g = gcd(a,b,x0,y0);
    double lo1 = -((double)x0*c*b + (double)x2*g/b);
    double lo2 = ((double)y1*g/a + (double)y0*c/a);
    double hi1 = -((double)x0*c*b + (double)x1*g/b);
    double hi2 = ((double)y2*g/a + (double)y0*c/a);

    lli h1 = floor(hi1);
    lli h2 = floor(hi2);
    lli l1 = ceil(lo1);
    lli l2 = ceil(lo2);

    lli h = min(h1,h2);
    lli l = max(l1,l2);

    lli ans = abs(h-l) + 1;

    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}