//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(lli mid, lli k,vector<lli> &A,vector<lli> &B){
    lli n = A.size();
    lli m = B.size();
    lli cnt = 0;
    // cout<<mid<<endl;
    for(lli i=0;i<n;i++){
        lli ind = upper_bound(B.begin(),B.end(),mid-A[i]) - B.begin();
        cnt += ind;
        if(cnt >= k) return 1;
    }
    return 0;
}

void solve()
{
    lli n,m,k;
    cin>>n>>m>>k;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    vector<lli> vec2(m,0);
    for(auto &it:vec2){
        cin>>it;
    }

    if(n > m){
        swap(n,m);
        swap(vec,vec2);
    }
    sort(all(vec));
    sort(all(vec2));

    lli st = vec[0] + vec2[0];
    lli en = vec.back() + vec2.back();
    lli ans = 0;

    while(st<=en){
        lli mid = st + (en-st)/2;
        if(check(mid,k,vec,vec2)){
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