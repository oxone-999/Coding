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
    lli n;
    cin>>n;

    string s;
    cin>>s;
    lli ans = 0;

    for(lli i=0;i<26;i++){
        char c = 'a'+i;

        vector<lli> vec;
        vec.push_back(-1);

        for(lli j=0;j<n;j++){
            if(s[j] == c) vec.push_back(j);
        }
        vec.push_back(n);

        for(lli j=1;j<vec.size()-1;j++){
            ans += (vec[j]-vec[j-1])*(n-vec[j]);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}