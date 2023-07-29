//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(int mid,vector<int> &vec){
    if(vec[0] > vec[mid]) return 1;
    else return 0;
}

void solve()
{
    int n;
    cin>>n;
    
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    int st = 0;
    int en = n-1;
    int ans = 0;

    while(st<=en){
        int mid = en + (st-en)/2;
        if(check(mid,vec)){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}