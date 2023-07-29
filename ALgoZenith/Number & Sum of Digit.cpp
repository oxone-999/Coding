//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(lli mid, lli s){
    string str = to_string(mid);
    lli num = 0;
    for(auto it:str){
        num += it-'0';
        if(mid - num < s) return 0;
    }
    return 1;
}

void solve()
{
    lli n,s;
    cin>>n>>s;

    lli st = 1;
    lli en = n;
    lli ans = n+1;

    while(st<=en){
        lli mid = st+(en-st)/2;
        if(check(mid,s)){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }
    if(ans == n+1) cout<<0<<endl;
    else cout<<n-ans+1<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}