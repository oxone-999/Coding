//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    set<int> s;
    set<int> t;

    while(n--){
        int ch,x;
        cin>>ch>>x;

        if(ch == 1){
            s.insert(x);
            t.erase(x);
            if(!s.count(x+1)) t.insert(x+1);
        }else{
            if(!s.count(x)) cout<<x<<endl;
            else cout<<*t.lower_bound(x)<<endl;
        }
    }	
}

signed main(){
    IOS
    int t=1;cin>>t;while(t--) solve();
    return 0;
}