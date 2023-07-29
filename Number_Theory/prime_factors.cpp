#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

vector<pair<int,int>> factors(int n){
    vector<pair<int,int>> ans;

    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            int cnt = 0;
            while(n%i == 0){
                cnt++;
                n /= i;
            }
            ans.push_back({i,cnt});
        }
    }
    if(n != 1) ans.push_back({n,1});
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> vec = factors(n);
    for(auto it:vec){
        cout<<it.first<<" "<<it.second<<endl;
    }	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}