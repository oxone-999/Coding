//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(vector<lli> &vec,lli k,lli mid){
    lli cnt = 1;
    lli sum = 0;
    for(auto it:vec){
        sum += it;
        if(sum > mid){
            sum = it;
            cnt++;
            if(cnt > k) return 0;
        }
    }
    return 1;
}

void solve()
{
    lli n,k;
    cin>>n>>k;
    
    vector<lli> vec(n,0);
    lli sum = 0;
    lli mx = LLONG_MIN;
    for(auto &it:vec){
        cin>>it;
        sum += it;
        mx = max(mx,it);
    }

    lli st = mx;
    lli en = sum;
    lli ans = 0;
    while(st <= en){
        lli mid = st + (en-st)/2;
        if(check(vec,k,mid)){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}