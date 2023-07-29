#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

vector<int> factors(int N){
    vector<int> ans;
    for(int i=1;i*i<=N;i++){
        if(N%i == 0){
            ans.push_back(i);
            if(i*i != N){
                ans.push_back(N/i);
            }
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> vec = factors(n);
    sort(vec.begin(),vec.end());
    for(auto it:vec){
        cout<<it<<" ";
    }	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}