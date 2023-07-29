#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    string s;
    cin>>s;

    int n,m;
    cin>>n>>m;
    int l = s.size();

    int i = l-1;
    int ans = 0;
    while(i != 0){
        if(i-n < 0)
            i = l-n-i;
        else i -= n;
        ans++;
        if(i == 0) break;
        if(i-m < 0)
            i = l-m-i;
        else i -= m;
        ans++;
    }   
    cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}