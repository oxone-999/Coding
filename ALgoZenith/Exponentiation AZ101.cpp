//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

// //DEBUGGER
// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }


lli mul(lli a,lli b,lli mod){
    lli ans = (a*b)%mod;
    if(ans<0) ans += mod;
    return ans;
}
lli binpow(lli a,lli b,lli mod){
    if(b==0)return 1;
    if(b==1)return a%mod;
    if((b%2)!=0){
        return mul(a,binpow(a,b-1,mod),mod);
    }else{
        lli temp = binpow(a,b/2,mod);
        return mul(temp,temp,mod);
    }
}

void solve()
{
    lli A,B,C,P;
    cin>>A>>B>>C>>P;

    if(A == 0){
        if(B == 0){
            if(C == 0) cout<<0<<endl;
            else cout<<1<<endl;
        }else cout<<0<<endl;
    }else{
        if(B == 0){
            if(C == 0) cout<<(A%P)<<endl;
            else cout<<1<<endl;
        }else{
            if(A % P == 0) cout<<0<<endl;
            else {
                lli z = binpow(B,C,P-1);
                lli y = binpow(A,z,P);
                cout<<y<<endl;
            }
        }   
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}