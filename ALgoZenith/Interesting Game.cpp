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
    
    vector<lli> vec(n,0);

    for(lli i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<lli> vec2(n,0);
    for(lli i=0;i<n;i++){
        cin>>vec2[i];
    }

    pair<int,int> v[n];
    for(int i=0;i<n;i++){
        v[i] = {vec[i]+vec2[i],i};
    }
    sort(v,v+n);

    lli x = 0;
    bool phase = true;
    while(n--){
        if(phase){
            x += vec[v[n].second];
            phase = false;
        }else{
            x -= vec2[v[n].second];
            phase = true;
        }
    }
    if(x > 0) cout<<"Alice"<<endl;
    else if(x == 0) cout<<"Tie"<<endl;
    else cout<<"Bob"<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}