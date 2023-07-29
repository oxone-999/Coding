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
    string input;
    while(getline(cin,input)){
        istringstream iss(input);

        lli a,b;

        if(iss>>a>>b){
            lli x,y,g;
            g = gcd(a,b,x,y);
            cout<<x<<" "<<y<<" "<<g<<endl;
        }
    }
    return 0;
}