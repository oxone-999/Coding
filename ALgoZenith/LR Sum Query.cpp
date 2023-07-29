//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const ll mod = 1e9+7;

// //DEBUGGER
// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }


void solve()
{
    ll n,q;
    cin>>n>>q;
    
    vector<ll> vec(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
        vec[i] += vec[i-1];
        while(vec[i] < 0) vec[i] += mod;
        while(vec[i] > mod) vec[i] -= mod;
    }


    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        ll ans = vec[r]-vec[l-1];
        while(ans < 0) ans += mod;
        while(ans > mod) ans -= mod;
        cout<<ans<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}