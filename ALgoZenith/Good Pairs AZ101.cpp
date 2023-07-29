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
    for(auto &it:vec){
        cin>>it;
    }
    vector<lli> vec2(n,0);
    for(auto &it:vec2){
        cin>>it;
    }

    vector<lli> vec3(n,0);
    for(lli i=0;i<n;i++){
        vec3[i] = vec[i] - vec2[i];
    }

    sort(all(vec3));
    lli cnt = 0;

    for(lli i=0;i<n;i++){
        lli target = -vec3[i];
        lli ind = upper_bound(vec3.begin()+i+1,vec3.end(),target) - vec3.begin();
        if(ind < n) cnt += n-ind;
    }
    cout<<cnt<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}