#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x = a*d;
    int y = b*c;
    if(x == y) cout<<0<<endl;
    else{
        if(x < y) swap(x,y);
        if(y == 0 || x % y == 0) cout<<1<<endl;
        else cout<<2<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}