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

signed main(){
    IOS
    while(1){
        lli n,m,a,k;
        cin>>n>>m>>a>>k;

        if(n == 0 && m == 0 && a == 0 && k == 0) return 0;
        // cerr<<n<<m<<a<<k;
        lli g = __gcd(m,a);
        // cerr<<g;
        if(k-n == 0 || g == 0 || g % (k-n) != 0){
            cout<<"Impossible"<<endl;
        }else{
            lli x,y;
            gcd(m,a,x,y);

            y = -y;
            x = x*(k-n)/g;
            y = y*(k-n)/g;

            lli ans = n + x * m;

            if(ans < 0){
                while(ans < 0){
                    x += a/g;
                    ans = n + x*m; 
                }
            }else if(ans > 0){
                while(n+(x*m) > 0){
                    ans = n + x*m;
                    x -= a/g;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}