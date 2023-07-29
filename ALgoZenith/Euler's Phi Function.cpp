//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

void solve()
{
    lli n;
    cin>>n;

    lli x = n;

    for(lli i=2;i*i<=n;i++){
        bool is = false;
        while(n % i == 0){
            n /= i;
            is = true;
        }        
        if(is){
            x -= x/i;
        }
    }
    if(n > 1) x -= x/n;
    cout<<x<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}