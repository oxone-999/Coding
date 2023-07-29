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

bool check(vector<lli> &vec,lli k,lli mid){
    lli x = 0;
    lli n = vec.size();
    for(lli i=0;i<n;i++){
        lli y = vec[i];
        lli z = 0;
        if(y % 2 != 0){
            y--;
            x++;
        } 
        while(y > mid){
            y = y/2;
            z++;
        }
        x += power(2,z)-1;
        if(x > k) return 0;
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
        mx = max<lli>(mx,it);
        sum += it;
    }
    if(k == 0){
        cout<<mx<<endl;
        return;
    }
    sort(vec.begin(),vec.end(),greater<lli>());

    lli st = 1;
    lli en = 1e9;
    lli ans = st;

    while(st <= en){
        lli mid = st+(en-st)/2;
        if(check(vec,k,mid)){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }
    if(sum == 0) cout<<sum<<endl;
    else cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}