#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

vector<int> seive(int n){
    vector<int> vec;
    vector<int> prime(n+1,0);

    for(int i=2;i<=n;i++){
        prime[i] = 1;
    }
    for(int i=2;i<=n;i++){
        if(prime[i]){
            for(long long j = 1ll*i*i;j<=n;j+=i){
                prime[j] = 0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) vec.push_back(i);
    }
    return vec;
}

void solve()
{
    int a,b;
    cin>>a>>b;

    vector<int> vec = seive(b);
    vector<int> vec2 = seive(a);
    vector<int> ans;
    bool phase = false;
    for(auto it:vec){
        if(phase) ans.push_back(it);
        if(it == vec2.back()){
            phase = !phase;
        }
    }

    for(auto it:ans){
        cout<<it<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}