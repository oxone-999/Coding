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
    
    lli m = pow(2,n);
    vector<lli> vec(m,0);
    for(auto &it:vec){
        cin>>it;
    }

    if(n == 1){
        cout<<vec[1]<<endl;
        return;
    }

    sort(all(vec));

    multiset<lli> s(vec.begin()+2,vec.end());
    vector<lli> ans;
    ans.push_back(vec[1]);

    while((lli)ans.size() < n){
        lli x = *s.begin();
        s.erase(s.find(x));
        for(auto it:ans){
            lli y = x + it;
            if(s.find(y) != s.end()) s.erase(s.find(y));
        }
        ans.push_back(x);
    }

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}