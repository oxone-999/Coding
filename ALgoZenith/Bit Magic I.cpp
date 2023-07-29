//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

//Power
lli power(lli x,lli y){
  lli ans = 1;
  while(y--) ans*=x;
  return ans;
}

void solve()
{
    lli n = 0;

    lli q;
    cin>>q;

    for(lli i=0;i<q;i++){
        lli ch;
        cin>>ch;

        if(ch == 1){
            lli x;
            cin>>x;
            if((n & (1LL<<x))) cout<<1<<endl;
            else cout<<0<<endl;
        }else if(ch == 2){
            lli x;
            cin>>x;
            n = n | (1LL<<x);
        }else if(ch == 3){
            lli x;
            cin>>x;
            n = n & ~(1LL<<x);
        }else if(ch == 4){
            lli x;
            cin>>x;
            n = n ^ (1LL<<x);
        }else if(ch == 5){
            if(__builtin_popcountll(n) == 60) cout<<1<<endl;
            else cout<<0<<endl;
        }else if(ch == 6){
            if(__builtin_popcountll(n) >= 1) cout<<1<<endl;
            else cout<<0<<endl;
        }else if(ch == 7){
            if(__builtin_popcountll(n) == 0) cout<<1<<endl;
            else cout<<0<<endl;
        }else if(ch == 8){
            cout<<__builtin_popcountll(n)<<endl;
        }else if(ch == 9){
            cout<<n<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}