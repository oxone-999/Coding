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
    int a,b,c;
    cin>>a>>b>>c;

    if(c % __gcd(a,b) == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    IOS
    int x = 1;
    lli t=1;cin>>t;
    while(t--){
        cout<<"Case "<<x<<": ";
        solve();
        x++;
    } 
    return 0;
}